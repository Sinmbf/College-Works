"""
Face Mask Detection Web Application
=====================================
A Streamlit-based web app that uses a CNN model to detect
whether a person in an uploaded image is wearing a face mask.

Author: Generated from Face_Mask_Detection.ipynb
Model Input: 128x128 RGB image
Model Output: [prob_no_mask, prob_mask]
"""

import streamlit as st
import numpy as np
from PIL import Image
import io
import time

# Local utility modules
from utils.preprocess import preprocess_image, validate_image
from utils.predictor import load_model, predict_mask


# ─────────────────────────────────────────────
#  PAGE CONFIG  (must be the very first st call)
# ─────────────────────────────────────────────
st.set_page_config(
    page_title="MaskSense · Face Mask Detector",
    page_icon="😷",
    layout="centered",
    initial_sidebar_state="collapsed",
)


# ─────────────────────────────────────────────
#  INJECT CUSTOM CSS
# ─────────────────────────────────────────────
st.markdown(
    """
    <style>
    /* ── Google Fonts ── */
    @import url('https://fonts.googleapis.com/css2?family=DM+Mono:wght@400;500&family=Syne:wght@700;800&family=DM+Sans:wght@300;400;500&display=swap');

    /* ── Global reset ── */
    html, body, [class*="css"] {
        font-family: 'DM Sans', sans-serif;
    }

    /* ── Background ── */
    .stApp {
        background: #0d0f14;
        color: #e8eaf0;
    }

    /* ── Hide Streamlit chrome ── */
    #MainMenu, footer, header { visibility: hidden; }
    .block-container { padding-top: 2rem; max-width: 760px; }

    /* ── Hero title ── */
    .hero-title {
        font-family: 'Syne', sans-serif;
        font-size: clamp(2.4rem, 6vw, 3.6rem);
        font-weight: 800;
        letter-spacing: -0.03em;
        line-height: 1.1;
        background: linear-gradient(135deg, #e8eaf0 30%, #6c8aff 100%);
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        background-clip: text;
        margin-bottom: 0.2rem;
    }

    .hero-sub {
        font-family: 'DM Mono', monospace;
        font-size: 0.78rem;
        letter-spacing: 0.18em;
        color: #6c8aff;
        text-transform: uppercase;
        margin-bottom: 2.4rem;
    }

    /* ── Divider ── */
    .thin-rule {
        border: none;
        border-top: 1px solid #1e2230;
        margin: 1.6rem 0;
    }

    /* ── Upload zone ── */
    [data-testid="stFileUploader"] {
        background: #13161f;
        border: 1.5px dashed #2a2f42;
        border-radius: 16px;
        padding: 1.2rem;
        transition: border-color 0.2s;
    }
    [data-testid="stFileUploader"]:hover {
        border-color: #6c8aff;
    }
    [data-testid="stFileUploader"] label {
        color: #8890aa !important;
        font-size: 0.88rem;
    }

    /* ── Result card ── */
    .result-card {
        border-radius: 20px;
        padding: 2rem 2.4rem;
        margin-top: 1.6rem;
        position: relative;
        overflow: hidden;
    }
    .result-card-mask {
        background: linear-gradient(135deg, #0a1f12 0%, #0d2a18 100%);
        border: 1.5px solid #1a5c30;
    }
    .result-card-nomask {
        background: linear-gradient(135deg, #1f0a0a 0%, #2a0d0d 100%);
        border: 1.5px solid #5c1a1a;
    }

    .result-label {
        font-family: 'Syne', sans-serif;
        font-size: 2rem;
        font-weight: 800;
        letter-spacing: -0.02em;
    }
    .result-label-mask  { color: #3ddc84; }
    .result-label-nomask { color: #ff6b6b; }

    .result-icon {
        font-size: 3rem;
        margin-bottom: 0.6rem;
        display: block;
    }

    .result-conf-text {
        font-family: 'DM Mono', monospace;
        font-size: 0.8rem;
        color: #8890aa;
        margin-top: 0.3rem;
        letter-spacing: 0.06em;
    }

    /* ── Confidence bar ── */
    .conf-bar-wrapper {
        background: #1e2230;
        border-radius: 99px;
        height: 10px;
        margin-top: 1rem;
        overflow: hidden;
    }
    .conf-bar-fill-mask {
        background: linear-gradient(90deg, #1a9e5a, #3ddc84);
        height: 100%;
        border-radius: 99px;
        transition: width 0.8s ease;
    }
    .conf-bar-fill-nomask {
        background: linear-gradient(90deg, #c0392b, #ff6b6b);
        height: 100%;
        border-radius: 99px;
        transition: width 0.8s ease;
    }

    /* ── Small info badge ── */
    .info-badge {
        display: inline-block;
        background: #13161f;
        border: 1px solid #2a2f42;
        border-radius: 8px;
        padding: 0.25rem 0.7rem;
        font-family: 'DM Mono', monospace;
        font-size: 0.72rem;
        color: #6c8aff;
        margin-right: 0.4rem;
        margin-top: 0.5rem;
    }

    /* ── Image display ── */
    [data-testid="stImage"] img {
        border-radius: 14px;
        border: 1.5px solid #1e2230;
    }

    /* ── Spinner text ── */
    .stSpinner > div {
        color: #6c8aff !important;
    }

    /* ── Warning / error ── */
    .stAlert {
        border-radius: 12px;
        font-size: 0.88rem;
    }

    /* ── Sidebar ── */
    [data-testid="stSidebar"] {
        background: #0d0f14;
        border-right: 1px solid #1e2230;
    }
    </style>
    """,
    unsafe_allow_html=True,
)


# ─────────────────────────────────────────────
#  LOAD MODEL  (cached so it runs only once)
# ─────────────────────────────────────────────
@st.cache_resource(show_spinner=False)
def get_model():
    """Load the trained CNN model once and cache it for the session."""
    return load_model()


# ─────────────────────────────────────────────
#  HEADER
# ─────────────────────────────────────────────
st.markdown('<p class="hero-title">MaskSense</p>', unsafe_allow_html=True)
st.markdown(
    '<p class="hero-sub">CNN · Face Mask Detection · TensorFlow / Keras</p>',
    unsafe_allow_html=True,
)

st.markdown(
    """
    Upload a clear photo of a person's face. The model will analyse the image and
    tell you whether they are wearing a face mask — along with a confidence score.
    """,
)

st.markdown('<hr class="thin-rule">', unsafe_allow_html=True)


# ─────────────────────────────────────────────
#  SIDEBAR  –  model + tech info
# ─────────────────────────────────────────────
with st.sidebar:
    st.markdown("### 🧠 Model Info")
    st.markdown(
        """
        | Property | Value |
        |---|---|
        | Architecture | CNN |
        | Input size | 128 × 128 |
        | Channels | RGB |
        | Output classes | 2 |
        | Framework | TensorFlow / Keras |
        """
    )
    st.markdown("---")
    st.markdown("### 📋 Preprocessing")
    st.markdown(
        """
        1. Read image → NumPy array
        2. Convert BGR → RGB
        3. Resize to 128 × 128
        4. Normalise pixels ÷ 255
        5. Reshape → (1, 128, 128, 3)
        """
    )
    st.markdown("---")
    st.markdown("### 🏷️ Labels")
    st.markdown("- `0` → **No Mask**")
    st.markdown("- `1` → **Mask**")


# ─────────────────────────────────────────────
#  FILE UPLOADER
# ─────────────────────────────────────────────
uploaded_file = st.file_uploader(
    "Drop an image here, or click to browse",
    type=["jpg", "jpeg", "png", "webp", "bmp"],
    help="Supported formats: JPG, JPEG, PNG, WEBP, BMP",
)

# ─────────────────────────────────────────────
#  MAIN PREDICTION FLOW
# ─────────────────────────────────────────────
if uploaded_file is not None:

    # ── Read raw bytes once
    img_bytes = uploaded_file.read()

    # ── Validate image
    valid, err_msg = validate_image(img_bytes)
    if not valid:
        st.error(f"⚠️ {err_msg}")
        st.stop()

    # ── Open with PIL for display (preserves original colours)
    pil_image = Image.open(io.BytesIO(img_bytes)).convert("RGB")

    col_img, col_meta = st.columns([1.4, 1], gap="large")

    with col_img:
        st.markdown("**Preview**")
        st.image(pil_image, use_container_width=True)

    with col_meta:
        st.markdown("**Image Details**")
        w, h = pil_image.size
        file_kb = len(img_bytes) / 1024
        st.markdown(
            f"""
            <span class="info-badge">📐 {w} × {h} px</span>
            <span class="info-badge">💾 {file_kb:.1f} KB</span>
            <span class="info-badge">🎨 RGB</span>
            """,
            unsafe_allow_html=True,
        )

        st.markdown("<br>", unsafe_allow_html=True)
        run_btn = st.button("🔍 Analyse Image", use_container_width=True, type="primary")

    st.markdown('<hr class="thin-rule">', unsafe_allow_html=True)

    # ── Run prediction when button pressed
    if run_btn:
        model = get_model()

        if model is None:
            st.error(
                "❌ Model file not found. Place your trained `model.h5` inside the "
                "`model/` directory and restart the app."
            )
            st.stop()

        with st.spinner("Analysing …"):
            # Simulate a brief processing feel for UX
            time.sleep(0.3)

            # Preprocess image for the model
            processed = preprocess_image(img_bytes)

            # Get prediction
            label, confidence, raw_probs = predict_mask(model, processed)

        # ── Display result card
        is_mask = label == 1
        card_class = "result-card-mask" if is_mask else "result-card-nomask"
        label_class = "result-label-mask" if is_mask else "result-label-nomask"
        icon = "😷" if is_mask else "🚫"
        label_text = "Mask Detected" if is_mask else "No Mask Detected"
        conf_pct = confidence * 100
        bar_class = "conf-bar-fill-mask" if is_mask else "conf-bar-fill-nomask"

        st.markdown(
            f"""
            <div class="result-card {card_class}">
                <span class="result-icon">{icon}</span>
                <div class="result-label {label_class}">{label_text}</div>
                <div class="result-conf-text">Confidence: {conf_pct:.2f}%</div>
                <div class="conf-bar-wrapper">
                    <div class="{bar_class}" style="width:{conf_pct:.1f}%"></div>
                </div>
            </div>
            """,
            unsafe_allow_html=True,
        )

        # ── Breakdown table
        st.markdown("<br>", unsafe_allow_html=True)
        st.markdown("**Probability Breakdown**")
        col_a, col_b = st.columns(2)
        with col_a:
            st.metric(
                label="😷 Mask",
                value=f"{raw_probs[1]*100:.2f}%",
                delta="predicted" if is_mask else None,
            )
        with col_b:
            st.metric(
                label="🚫 No Mask",
                value=f"{raw_probs[0]*100:.2f}%",
                delta="predicted" if not is_mask else None,
            )

else:
    # ── Empty state hint
    st.markdown(
        """
        <div style="text-align:center; padding: 3rem 0; color:#3a4060;">
            <div style="font-size:3rem; margin-bottom:0.8rem;">📸</div>
            <div style="font-family:'DM Mono',monospace; font-size:0.82rem; letter-spacing:0.1em;">
                AWAITING IMAGE UPLOAD
            </div>
        </div>
        """,
        unsafe_allow_html=True,
    )
