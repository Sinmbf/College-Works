"""
utils/preprocess.py
====================
Image preprocessing utilities for the Face Mask Detection app.

Pipeline (mirrors the original notebook):
  1. Decode raw bytes → NumPy array via OpenCV
  2. Convert BGR → RGB
  3. Resize to MODEL_INPUT_SIZE
  4. Normalise pixel values (÷ 255)
  5. Reshape into batch format (1, H, W, 3)
"""

import io
import numpy as np
import cv2
from PIL import Image, UnidentifiedImageError

# ── Model constants ────────────────────────────────────────────────────────────
MODEL_INPUT_SIZE = (128, 128)   # Expected (width, height) for model input


def validate_image(img_bytes: bytes) -> tuple[bool, str]:
    """
    Validate that the uploaded bytes represent a readable image.

    Parameters
    ----------
    img_bytes : bytes
        Raw bytes of the uploaded file.

    Returns
    -------
    (is_valid : bool, error_message : str)
        If valid, error_message is an empty string.
    """
    if not img_bytes:
        return False, "No image data received. Please upload a valid file."

    try:
        # PIL can detect corrupt / unsupported images quickly
        img = Image.open(io.BytesIO(img_bytes))
        img.verify()        # raises if file is corrupt
    except UnidentifiedImageError:
        return False, "The uploaded file is not a recognised image format."
    except Exception as exc:
        return False, f"Image validation failed: {exc}"

    return True, ""


def decode_image(img_bytes: bytes) -> np.ndarray:
    """
    Decode raw image bytes into a NumPy array in BGR colour space (OpenCV default).

    Parameters
    ----------
    img_bytes : bytes
        Raw bytes of the image file.

    Returns
    -------
    np.ndarray  shape (H, W, 3)  dtype uint8  BGR colour order
    """
    # Convert bytes → numpy byte array → OpenCV BGR image
    np_arr = np.frombuffer(img_bytes, dtype=np.uint8)
    img_bgr = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
    return img_bgr


def bgr_to_rgb(img_bgr: np.ndarray) -> np.ndarray:
    """
    Convert an image from BGR (OpenCV default) to RGB (model expectation).

    Parameters
    ----------
    img_bgr : np.ndarray  shape (H, W, 3)

    Returns
    -------
    np.ndarray  shape (H, W, 3)  RGB colour order
    """
    return cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)


def resize_image(img_rgb: np.ndarray, size: tuple = MODEL_INPUT_SIZE) -> np.ndarray:
    """
    Resize image to the target size expected by the CNN.

    Parameters
    ----------
    img_rgb : np.ndarray  shape (H, W, 3)
    size    : (width, height) — default (128, 128)

    Returns
    -------
    np.ndarray  shape (size[1], size[0], 3)
    """
    return cv2.resize(img_rgb, size)


def normalize_image(img: np.ndarray) -> np.ndarray:
    """
    Normalise pixel values from [0, 255] to [0.0, 1.0].

    Parameters
    ----------
    img : np.ndarray  dtype uint8

    Returns
    -------
    np.ndarray  dtype float32
    """
    return img.astype(np.float32) / 255.0


def reshape_for_model(img: np.ndarray) -> np.ndarray:
    """
    Add a batch dimension so the array matches model.predict() expectations.

    Parameters
    ----------
    img : np.ndarray  shape (128, 128, 3)

    Returns
    -------
    np.ndarray  shape (1, 128, 128, 3)
    """
    return np.reshape(img, [1, MODEL_INPUT_SIZE[1], MODEL_INPUT_SIZE[0], 3])


def preprocess_image(img_bytes: bytes) -> np.ndarray:
    """
    Full preprocessing pipeline — goes from raw bytes to model-ready tensor.

    Steps
    -----
    1. Decode bytes with OpenCV (BGR)
    2. Convert BGR → RGB
    3. Resize to 128 × 128
    4. Normalise ÷ 255
    5. Reshape to (1, 128, 128, 3)

    Parameters
    ----------
    img_bytes : bytes
        Raw image file bytes.

    Returns
    -------
    np.ndarray  shape (1, 128, 128, 3)  float32 values in [0, 1]
    """
    img_bgr      = decode_image(img_bytes)
    img_rgb      = bgr_to_rgb(img_bgr)
    img_resized  = resize_image(img_rgb)
    img_scaled   = normalize_image(img_resized)
    img_batched  = reshape_for_model(img_scaled)
    return img_batched
