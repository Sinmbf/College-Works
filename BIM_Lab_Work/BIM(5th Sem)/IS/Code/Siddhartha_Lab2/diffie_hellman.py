# Diffie-Hellman Key Exchange Implementation

'''
    Diffie-Hellman key exchange works because: 
        => (g^a)^b mod p = (g^b)^a mod p
    Both parties compute the same shared secret without ever sending their private keys.
'''

# Publicly agreed values
p = int(input("Enter a prime number (p): "))
g = int(input("Enter a primitive root (g): "))

# Alice's private key
a = int(input("Enter Alice's private key: "))

# Bob's private key
b = int(input("Enter Bob's private key: "))

# Alice computes public value
A = pow(g, a, p)

# Bob computes public value
B = pow(g, b, p)

print("\nPublic Values:")
print("Alice sends:", A)
print("Bob sends:", B)

# Shared secret calculation
alice_secret = pow(B, a, p)
bob_secret = pow(A, b, p)

print("\nShared Secret (Alice):", alice_secret)
print("Shared Secret (Bob):", bob_secret)

if alice_secret == bob_secret:
    print("\nKey Exchange Successful!")
else:
    print("\nError in Key Exchange!")