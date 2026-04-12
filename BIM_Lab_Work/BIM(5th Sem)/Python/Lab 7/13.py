data1 = {"a": 1}
data2 = {"b": 2}

with open("multi.bin", "wb") as f:
    f.write((str(data1) + "\n").encode())
    f.write((str(data2) + "\n").encode())

print("Objects written")