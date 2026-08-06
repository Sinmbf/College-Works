import numpy as np

# Step Activation Function
def activation(x):
    return 1 if x >= 0 else 0

# Input Data (AND Gate)
X = np.array([
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
])

# Target Output
y = np.array([0, 0, 0, 1])

# Initialize Weights and Bias
weights = np.zeros(2)
bias = 0

# Parameters
learning_rate = 0.1
epochs = 4

print("Training the Perceptron...\n")

# Training
for epoch in range(epochs):
    for i in range(len(X)):
        net = np.dot(X[i], weights) + bias
        prediction = activation(net)

        error = y[i] - prediction

        # Update weights and bias
        weights = weights + learning_rate * error * X[i]
        bias = bias + learning_rate * error

    # Display after each epoch
    print(f"Epoch {epoch + 1}")
    print(f"Weights: {weights}")
    print(f"Bias: {bias}\n")

# Final Prediction
print("Final Prediction")
print("Input\tPredicted\tActual")

for i in range(len(X)):
    net = np.dot(X[i], weights) + bias
    prediction = activation(net)
    print(f"{X[i]}\t   {prediction}\t\t   {y[i]}")