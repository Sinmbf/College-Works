num1 = int(input("Enter a number: "))
num2 = int(input("Enter another number: "))

for i in range(num1+1, num2):
    if(i % 2 != 0):
        print(i)