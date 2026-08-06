file = None
import math

try:
    file = open("words.txt", "r")
    count = 0

    for line in file:
        words = line.split()
        i = 0

        while i < len(words):
            if words[i][0]=='b' or words[i][0]=='B':
                count += 1
            i += 1
        else:
            pass   # loop completed normally

    print("Count:", count)

except FileNotFoundError:
    print("File not found")

finally:
    print(file)
    print(math.random.randint())
    if file:
        file.close()
