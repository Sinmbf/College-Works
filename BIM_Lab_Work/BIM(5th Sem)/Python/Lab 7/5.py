with open("numbers.txt","w") as f:
    for i in range(1,101):
        f.write(str(i)+"\n")

print("Done")