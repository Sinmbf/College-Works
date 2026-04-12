with open("grades.txt", "w") as file:
    for i in range(2):  # example
        name = input("Name: ")
        marks = []
        
        for j in range(5):
            m = int(input("Enter mark: "))
            marks.append(m)
        
        line = name
        for m in marks:
            line += " " + str(m)
        
        file.write(line + "\n")

# Read and process
with open("grades.txt", "r") as file:
    print("\nStudents with average > 50:")
    for line in file:
        data = line.split()
        name = data[0]
        marks = list(map(int, data[1:]))
        
        avg = sum(marks) / len(marks)
        
        if avg > 50:
            print(name)