###CELL 1

import cv2
import numpy as np
import pickle
import os
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from IPython.display import display, clear_output
os.environ["OPENCV_LOG_LEVEL"] = "SILENT"
print("Imports OK")

###CELL 1



###CELL 2

with open("/home/xilinx/jupyter_notebooks/mnist_mlp.pkl", "rb") as f:
    mlp = pickle.load(f)
print("Model loaded!")

###CELL 2



###CELL 3

def preprocess_digit(frame):
    gray    = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    thresh  = cv2.adaptiveThreshold(
        blurred, 255,
        cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
        cv2.THRESH_BINARY_INV,
        blockSize=11, C=2
    )
    contours, _ = cv2.findContours(
        thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
    )
    if not contours:
        return None, None
    largest = max(contours, key=cv2.contourArea)
    if cv2.contourArea(largest) < 500:
        return None, None
    x, y, w, h = cv2.boundingRect(largest)
    if w < 20 or h < 20:
        return None, None
    pad = 20
    x1 = max(x - pad, 0)
    y1 = max(y - pad, 0)
    x2 = min(x + w + pad, thresh.shape[1])
    y2 = min(y + h + pad, thresh.shape[0])
    cropped = thresh[y1:y2, x1:x2]
    size   = max(cropped.shape[0], cropped.shape[1])
    square = np.zeros((size, size), dtype=np.uint8)
    oy = (size - cropped.shape[0]) // 2
    ox = (size - cropped.shape[1]) // 2
    square[oy:oy+cropped.shape[0], ox:ox+cropped.shape[1]] = cropped
    resized    = cv2.resize(square, (28, 28), interpolation=cv2.INTER_AREA)
    normalized = resized.astype("float32") / 255.0
    return normalized, (x1, y1, x2, y2)

def predict_digit(img_28x28):
    flat       = img_28x28.flatten().reshape(1, -1)
    digit      = int(mlp.predict(flat)[0])
    proba      = mlp.predict_proba(flat)[0]
    confidence = float(np.max(proba)) * 100
    return digit, confidence

print("Functions defined OK")

###CELL 3



###CELL 4

import time
import base64
from IPython.display import display, HTML

# Create the HTML layout once
display(HTML("""
<div style="background:#1e1e1e; padding:10px; border-radius:8px; display:inline-block">
    <h2 id="digit_label" style="color:lime; font-family:monospace; text-align:center; margin:5px">
        Starting...
    </h2>
    <div style="display:flex; gap:8px;">
        <div style="text-align:center">
            <p style="color:white; font-size:12px; margin:2px">Camera Feed</p>
            <img id="panel_camera" width="240" style="border:2px solid #444"/>
        </div>
        <div style="text-align:center">
            <p style="color:white; font-size:12px; margin:2px">Grayscale</p>
            <img id="panel_gray" width="240" style="border:2px solid #444"/>
        </div>
        <div style="text-align:center">
            <p style="color:white; font-size:12px; margin:2px">Binarized</p>
            <img id="panel_binary" width="240" style="border:2px solid #444"/>
        </div>
    </div>
</div>
"""))

def to_b64(img_bgr):
    _, buf = cv2.imencode('.jpg', img_bgr, [cv2.IMWRITE_JPEG_QUALITY, 70])
    return base64.b64encode(buf).decode('utf-8')

def update_panels(camera_rgb, gray, thresh, label):
    # Convert back to BGR for imencode
    cam_b64    = to_b64(cv2.cvtColor(camera_rgb, cv2.COLOR_RGB2BGR))
    gray_b64   = to_b64(cv2.cvtColor(gray, cv2.COLOR_GRAY2BGR))
    thresh_b64 = to_b64(cv2.cvtColor(thresh, cv2.COLOR_GRAY2BGR))
    color      = "lime" if "Digit" in label else "orange"

    js = f"""
    document.getElementById('panel_camera').src  = 'data:image/jpeg;base64,{cam_b64}';
    document.getElementById('panel_gray').src     = 'data:image/jpeg;base64,{gray_b64}';
    document.getElementById('panel_binary').src   = 'data:image/jpeg;base64,{thresh_b64}';
    document.getElementById('digit_label').innerText = '{label}';
    document.getElementById('digit_label').style.color = '{color}';
    """
    display(HTML(f'<script>{js}</script>'))

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH,  320)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)
cap.set(cv2.CAP_PROP_FPS, 15)

for _ in range(5):
    cap.read()

print("Running — interrupt kernel to stop")

last_digit    = -1
stable_count  =  0
STABLE_NEEDED        = 3
CONFIDENCE_THRESHOLD = 85
current_label        = "Searching..."

try:
    while True:
        ret, frame = cap.read()
        if not ret:
            continue

        gray    = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        blurred = cv2.GaussianBlur(gray, (5, 5), 0)
        thresh  = cv2.adaptiveThreshold(
            blurred, 255,
            cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
            cv2.THRESH_BINARY_INV,
            blockSize=15, C=4
        )

        processed, bbox = preprocess_digit(frame)
        display_frame   = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        if processed is not None:
            digit, confidence = predict_digit(processed)
            if bbox:
                x1, y1, x2, y2 = bbox
                cv2.rectangle(display_frame,
                              (x1, y1), (x2, y2),
                              (0, 255, 0), 2)
            if confidence > CONFIDENCE_THRESHOLD:
                if digit == last_digit:
                    stable_count += 1
                else:
                    stable_count = 1
                    last_digit   = digit
                if stable_count >= STABLE_NEEDED:
                    current_label = f"Digit: {digit}  ({confidence:.1f}%)"
        else:
            stable_count  = 0
            last_digit    = -1
            current_label = "No digit detected"

        update_panels(display_frame, gray, thresh, current_label)

        del display_frame, frame, gray, blurred, thresh
        time.sleep(0.05)   # target ~15fps

except KeyboardInterrupt:
    print("Stopped.")
finally:
    cap.release()

###CELL 4