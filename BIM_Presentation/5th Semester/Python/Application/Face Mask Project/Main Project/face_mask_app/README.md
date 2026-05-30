# 😷 MaskSense — Face Mask Detection Web App

A production-ready **Streamlit** web application that uses a trained CNN (TensorFlow/Keras)
to detect whether a person in an uploaded photo is wearing a face mask.

---

## ✨ Features

| Feature | Detail |
|---|---|
| 📤 Image Upload | JPG / JPEG / PNG / WEBP / BMP |
| 🖼️ Preview | Original-colour image preview |
| 🧠 CNN Prediction | "Mask" or "No Mask" |
| 📊 Confidence % | Animated progress bar |
| 🟢🔴 Styled Results | Green = Mask · Red = No Mask |
| ⚠️ Error Handling | Corrupt / non-image files rejected gracefully |
| 📱 Responsive UI | Works on desktop and mobile |

---

## 🗂️ Project Structure

```
face_mask_app/
│
├── app.py                    ← Main Streamlit application
│
├── utils/
│   ├── __init__.py
│   ├── preprocess.py         ← Image preprocessing pipeline
│   └── predictor.py          ← Model loading & inference
│
├── model/
│   └── model.h5              ← YOUR trained model goes here ⬅️
│
├── .streamlit/
│   └── config.toml           ← Theme & server settings
│
├── requirements.txt
└── README.md
```

---

## 🚀 Local Setup (Step-by-Step)

### 1 — Clone / download the project

```bash
git clone https://github.com/your-username/face-mask-app.git
cd face-mask-app
```

### 2 — Create a virtual environment

```bash
# Windows
python -m venv venv
venv\Scripts\activate

# macOS / Linux
python -m venv venv
source venv/bin/activate
```

### 3 — Install dependencies

```bash
pip install -r requirements.txt
```

> **GPU users** — replace `tensorflow` with `tensorflow-gpu` in `requirements.txt`
> before running the above command.

### 4 — Add your trained model

Copy your trained model into the `model/` directory:

```bash
# From inside your notebook / training script
model.save('model/model.h5')
```

The file **must** be named `model.h5` and be in `.h5` (HDF5) Keras format.

### 5 — Run the app

```bash
streamlit run app.py
```

The app will open automatically at **http://localhost:8501**

---

## 🔧 Preprocessing Pipeline

The following steps are applied to every uploaded image (in `utils/preprocess.py`):

```
Raw bytes
   └─► OpenCV decode  (BGR array)
          └─► BGR → RGB  (cv2.COLOR_BGR2RGB)
                 └─► Resize to 128 × 128
                        └─► Normalise ÷ 255  (float32, range [0, 1])
                               └─► Reshape → (1, 128, 128, 3)
                                      └─► model.predict()
```

---

## 🏷️ Label Mapping

| Neuron index | Meaning |
|---|---|
| `0` | No Mask |
| `1` | Mask |

`np.argmax(prediction)` selects the winning class.

---

## 🌐 Deployment

### Option A — Streamlit Community Cloud (Free)

1. Push this project to a **public GitHub repository**.
2. Go to [share.streamlit.io](https://share.streamlit.io) and sign in.
3. Click **New app** → select your repo → set `app.py` as the entry point.
4. Add `model.h5` to the repo (or use Git LFS for large files):
   ```bash
   git lfs install
   git lfs track "model/*.h5"
   git add .gitattributes model/model.h5
   git commit -m "add model"
   git push
   ```
5. Click **Deploy**.

---

### Option B — Hugging Face Spaces (Free, GPU available)

1. Create a new **Space** at [huggingface.co/spaces](https://huggingface.co/spaces).
2. Choose **Streamlit** as the SDK.
3. Push your project files (the Space repo is a git repo).
4. Upload `model.h5` via the web UI or `git lfs`.

`requirements.txt` is picked up automatically.

---

### Option C — Render (Free tier)

1. Create a new **Web Service** at [render.com](https://render.com).
2. Connect your GitHub repo.
3. Set:
   - **Build command**: `pip install -r requirements.txt`
   - **Start command**: `streamlit run app.py --server.port $PORT --server.headless true`
4. Add `model.h5` to the repo (use Git LFS if > 100 MB).
5. Click **Deploy**.

---

### Option D — Docker

Create a `Dockerfile` in the project root:

```dockerfile
FROM python:3.11-slim

WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

EXPOSE 8501
CMD ["streamlit", "run", "app.py", "--server.port=8501", "--server.headless=true"]
```

Build and run:

```bash
docker build -t masksense .
docker run -p 8501:8501 masksense
```

---

## 🛠️ Troubleshooting

| Problem | Fix |
|---|---|
| `Model file not found` | Place `model.h5` inside the `model/` folder |
| `ModuleNotFoundError: tensorflow` | Run `pip install tensorflow` |
| Blank / broken image | Upload a valid JPG / PNG file |
| App crashes on large image | Streamlit default max upload is 10 MB (set in `config.toml`) |
| Wrong predictions | Check that your model was trained with the same preprocessing pipeline |

---

## 📦 Tech Stack

- **Python 3.9+**
- **Streamlit** — web framework
- **TensorFlow / Keras** — deep learning model
- **OpenCV** — image decoding & colour conversion
- **NumPy** — array operations
- **Pillow** — image display

---

## 📄 Licence

MIT — free to use, modify, and distribute.
