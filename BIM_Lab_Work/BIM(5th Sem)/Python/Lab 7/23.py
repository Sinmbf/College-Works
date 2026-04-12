with open("numbers.txt", "r") as file:
    lines = file.readlines()

print("Lines 5 to 10:")
for i in range(4, 10):  # index starts at 0
    if i < len(lines):
        print(lines[i].strip())