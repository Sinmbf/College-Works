data_list = []

with open("multi.bin", "rb") as f:
    for line in f:
        line = line.decode().strip()
        data_list.append(eval(line))   # reconstruct dictionary

print(data_list)