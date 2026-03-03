# Simple RSA Implementation (Educational Only)

'''
    RSA works because of Euler Algorithm:
        M^ed = M mod n (Congruent modulo)
'''

import math

# Step 1: Choose two prime numbers
p = 17
q = 11

# Step 2: Compute n
n = p * q

# Step 3: Compute phi(n)
phi = (p - 1) * (q - 1)

# Step 4: Choose e such that gcd(e, phi) = 1
e = 7

# Step 5: Compute d (modular inverse of e mod phi)
def mod_inverse(e, phi):
    for d in range(1, phi):
        if (e * d) % phi == 1:
            return d

d = mod_inverse(e, phi)

# Take input from user
# message must be less than 'n'
message = int(input("Enter message [less than 187]: "))

if message >= n:
    print("Error: Message must be less than", n)
else:
    print("Public Key:", (e, n))
    print("Private Key:", (d, n))
    # Encryption
    cipher = pow(message, e, n)
    print("Encrypted:", cipher)

    # Decryption
    decrypted = pow(cipher, d, n)
    print("Decrypted:", decrypted)
