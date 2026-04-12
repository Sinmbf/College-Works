text = input("Enter new content: ")

with open("file1.txt", "w") as f:
    f.write(text)

print("Overwritten")