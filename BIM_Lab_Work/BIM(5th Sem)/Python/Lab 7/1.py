data = ["Apple", "Banana", "Cherry"]

with open("file1.txt", "w") as f:
    for item in data:
        f.write(item + "\n")

print("Written successfully")