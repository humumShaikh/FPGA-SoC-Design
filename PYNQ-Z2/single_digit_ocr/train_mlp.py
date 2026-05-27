import numpy as np
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
import pickle
import urllib.request
import gzip

print("Downloading MNIST...")

# Faster mirror
base = "https://storage.googleapis.com/cvdf-datasets/mnist/"
files = {
    "train_images": "train-images-idx3-ubyte.gz",
    "train_labels": "train-labels-idx1-ubyte.gz",
    "test_images":  "t10k-images-idx3-ubyte.gz",
    "test_labels":  "t10k-labels-idx1-ubyte.gz",
}

for name, fname in files.items():
    urllib.request.urlretrieve(base + fname, fname)
    print(f"Downloaded {fname}")

def load_images(fname):
    with gzip.open(fname, 'rb') as f:
        f.read(16)
        return np.frombuffer(f.read(), dtype=np.uint8).reshape(-1, 784)

def load_labels(fname):
    with gzip.open(fname, 'rb') as f:
        f.read(8)
        return np.frombuffer(f.read(), dtype=np.uint8)

X_train = load_images("train-images-idx3-ubyte.gz") / 255.0
y_train = load_labels("train-labels-idx1-ubyte.gz")
X_test  = load_images("t10k-images-idx3-ubyte.gz")  / 255.0
y_test  = load_labels("t10k-labels-idx1-ubyte.gz")

print(f"Loaded: {X_train.shape[0]} train, {X_test.shape[0]} test samples")

print("\nTraining MLP...")
mlp = MLPClassifier(
    hidden_layer_sizes=(128, 64),
    activation='relu',
    max_iter=20,
    random_state=42,
    verbose=True
)
mlp.fit(X_train, y_train)

acc = mlp.score(X_test, y_test)
print(f"\nTest accuracy: {acc*100:.2f}%")

with open("mnist_mlp.pkl", "wb") as f:
    pickle.dump(mlp, f)

print("Saved: mnist_mlp.pkl")