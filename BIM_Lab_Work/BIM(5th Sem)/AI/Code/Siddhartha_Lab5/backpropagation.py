import numpy as np

# Activation function
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# Input and target
X = np.array([[1, 0, 1]])
y = np.array([[1]])

learning_rate = 0.9

# -------- USER INPUT --------
epochs = int(input("Enter number of epochs: "))

print("\nEnter weights (Input → Hidden layer: 3x2)")
W1 = np.array([[float(input("W1[1,4]: ")), float(input("W1[1,5]: "))],
               [float(input("W1[2,4]: ")), float(input("W1[2,5]: "))],
               [float(input("W1[3,4]: ")), float(input("W1[3,5]: "))]])

print("\nEnter biases for Hidden layer (1x2)")
b1 = np.array([[float(input("b1[4]: ")), float(input("b1[5]: "))]])

print("\nEnter weights (Hidden → Output layer: 2x1)")
W2 = np.array([[float(input("W2[4,6]: "))],
               [float(input("W2[5,6]: "))]])

print("\nEnter bias for Output layer")
b2 = np.array([[float(input("b2[6]: "))]])

# -------- TRAINING LOOP --------
for epoch in range(epochs):
    print(f"\n========== EPOCH {epoch + 1} ==========")

    # Forward propagation
    hidden_input = np.dot(X, W1) + b1
    hidden_output = sigmoid(hidden_input)

    output_input = np.dot(hidden_output, W2) + b2
    output = sigmoid(output_input)

    # Error
    error = y - output
    d_output = error * sigmoid_derivative(output)

    # Backpropagation
    error_hidden = d_output.dot(W2.T)
    d_hidden = error_hidden * sigmoid_derivative(hidden_output)

    # Update weights and biases
    W2 += learning_rate * hidden_output.T.dot(d_output)
    b2 += learning_rate * np.sum(d_output, axis=0, keepdims=True)

    W1 += learning_rate * X.T.dot(d_hidden)
    b1 += learning_rate * np.sum(d_hidden, axis=0, keepdims=True)

    # Print progress
    print("Output:", output)
    print("Error:", d_hidden,d_output)

# -------- FINAL OUTPUT --------
print("\n========== TRAINING COMPLETE ==========")
print("\nFinal Output:", output)

print("\nUpdated Weights Input → Hidden:\n", W1)
print("\nUpdated Bias Hidden:\n", b1)

print("\nUpdated Weights Hidden → Output:\n", W2)
print("\nUpdated Bias Output:\n", b2)