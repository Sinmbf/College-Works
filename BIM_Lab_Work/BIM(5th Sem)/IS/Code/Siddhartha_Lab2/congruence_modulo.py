def is_congruent(a, b, n):
    if n == 0:
        return "Modulo n cannot be zero."
    
    if (a - b) % n == 0:
        return f"{a} ≡ {b} (mod {n})"
    else:
        return f"{a} is NOT congruent to {b} (mod {n})"

# Taking user input
a = int(input("Enter first number (a): "))
b = int(input("Enter second number (b): "))
n = int(input("Enter modulus (n): "))

print(is_congruent(a, b, n))