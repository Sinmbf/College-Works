word = input("Enter word: ")

with open("file1.txt") as f:
    text = f.read()

print("Count:", text.count(word))