with open("file1.txt") as f:
    text = f.read()

words = text.split()
print("Word count:", len(words))