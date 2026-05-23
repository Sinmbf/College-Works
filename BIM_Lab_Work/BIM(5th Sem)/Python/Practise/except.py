try:
    f = open("file.txt")
    data = f.read()
    print(data)
except FileNotFoundError:
    print("File not found")