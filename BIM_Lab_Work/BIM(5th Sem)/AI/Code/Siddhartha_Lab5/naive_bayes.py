from collections import Counter

# Training data
data = [
    ("Sunny", "No", "Yes"),
    ("Sunny", "Yes", "No"),
    ("Rainy", "No", "Yes"),
    ("Rainy", "Yes", "Yes"),
    ("Sunny", "No", "Yes")
]

# Test instance
outlook = "Sunny"
windy = "No"

classes = [row[2] for row in data]
class_counts = Counter(classes)

total = len(data)

probabilities = {}

for cls in class_counts:

    prior = class_counts[cls] / total

    subset = [row for row in data if row[2] == cls]

    outlook_count = sum(1 for row in subset if row[0] == outlook)
    windy_count = sum(1 for row in subset if row[1] == windy)

    p_outlook = outlook_count / len(subset)
    p_windy = windy_count / len(subset)

    probabilities[cls] = prior * p_outlook * p_windy

prediction = max(probabilities, key=probabilities.get)

print("Probabilities:")
for cls, prob in probabilities.items():
    print(cls, "=", prob)

print("\nPredicted Class =", prediction)