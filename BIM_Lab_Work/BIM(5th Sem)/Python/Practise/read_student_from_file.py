try:
    f = open("students.txt", "r")
    
    for line in f:
        name = line.strip()
        
        if len(name) > 4:
            print(name[::-1])   # reverse name

except FileNotFoundError:
    print("File not found")

finally:
    try:
        f.close()
    except:
        pass