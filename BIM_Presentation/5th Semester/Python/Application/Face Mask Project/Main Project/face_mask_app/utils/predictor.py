"""
utils/predictor.py
===================
Model loading and inference utilities for the Face Mask Detection app.

Label mapping (matches notebook training):
  0 → No Mask   (output neuron index 0)
  1 → Mask      (output neuron index 1)
"""

import os
import numpy as np

# TensorFlow / Keras — imported lazily to avoid slowing the app at startup
# when the model file doesn't exist yet.
try:
    os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"   # suppress TF C++ logs
    import tensorflow as tf
    tf.get_logger().setLevel("ERROR")           # suppress Python-level TF logs
    _TF_AVAILABLE = True
except ImportError:
    _TF_AVAILABLE = False


# ── Path to the trained model ──────────────────────────────────────────────────
# Place your trained model file at  face_mask_app/model/model.h5
_MODEL_PATH = os.path.join(os.path.dirname(__file__), "..", "model", "model.h5")

# ── Class labels (index → human-readable) ─────────────────────────────────────
LABELS = {0: "No Mask", 1: "Mask"}


def load_model():
    """
    Load the pre-trained Keras CNN model from disk.

    The model is expected at: model/model.h5
    (relative to the project root).

    Returns
    -------
    keras.Model | None
        The loaded model, or None if the file is not found or TF unavailable.
    """
    if not _TF_AVAILABLE:
        print("❌ TensorFlow is not installed. Run: pip install tensorflow")
        return None

    model_path = os.path.abspath(_MODEL_PATH)

    if not os.path.exists(model_path):
        print(
            f"❌ Model file not found at: {model_path}\n"
            "   Please place your trained model.h5 in the model/ directory."
        )
        return None

    try:
        model = tf.keras.models.load_model(model_path)
        print(f"✅ Model loaded from {model_path}")
        return model
    except Exception as exc:
        print(f"❌ Failed to load model: {exc}")
        return None


def predict_mask(model, processed_image: np.ndarray) -> tuple:
    """
    Run inference on a preprocessed image and return the prediction.

    Parameters
    ----------
    model : keras.Model
        The loaded CNN model.
    processed_image : np.ndarray
        Shape (1, 128, 128, 3), float32, normalised to [0, 1].

    Returns
    -------
    label      : int    — 0 (No Mask) or 1 (Mask)
    confidence : float  — probability of the predicted class in [0, 1]
    raw_probs  : list   — [prob_no_mask, prob_mask]
    """
    # model.predict() returns shape (1, 2) — one row, two class probabilities
    prediction = model.predict(processed_image, verbose=0)   # shape: (1, 2)

    # Flatten to [prob_no_mask, prob_mask]
    raw_probs = prediction[0].tolist()

    # Predicted class index (0 or 1)
    label = int(np.argmax(prediction))

    # Confidence = probability of the winning class
    confidence = float(np.max(prediction))

    return label, confidence, raw_probs
