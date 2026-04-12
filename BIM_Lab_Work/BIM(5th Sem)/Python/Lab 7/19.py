n = 3

with open("university.txt","w") as f:
    f.write("ABC College,Kathmandu,50\n")
    f.write("XYZ College,Pokhara,30\n")

with open("university.txt") as f:
    print(f.read())