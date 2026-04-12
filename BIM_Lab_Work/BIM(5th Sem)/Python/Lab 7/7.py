n = int(input("Enter line number: "))

with open("numbers.txt") as f:
    lines = f.readlines()
    print(lines[n-1])