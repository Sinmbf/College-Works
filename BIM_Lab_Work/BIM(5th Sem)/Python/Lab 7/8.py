with open("file1.txt") as f:
    lines = f.readlines()

for line in reversed(lines):
    print(line.strip())