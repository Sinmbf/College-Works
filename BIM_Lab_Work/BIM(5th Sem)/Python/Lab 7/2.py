# with open("file1.txt", "a") as f:
#     f.write("Mango\n")

# print("Appended")

a = 10
b = 10

print("Initial addresses:")
print("a:", id(a))
print("b:", id(b))

a = 20

print("\nAfter changing a:")
print("a:", id(a))
print("b:", id(b))