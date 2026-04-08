import hashlib

# Small RSA keys (for learning)
e = 7
d = 103
n = 143   # 11 × 13

# Step 1: Hash
def hash_message(message):
    return int(hashlib.sha256(message.encode()).hexdigest(), 16)

# Step 2: Sign
def sign(message):
    h = hash_message(message)
    signature = pow(h, d, n)
    return signature

# Step 3: Verify with comparison
def verify(message, signature):
    h = hash_message(message)
    original_hash_mod = h % n
    decrypted_hash = pow(signature, e, n)

    print("\n--- Verification Details ---")
    print("Original Hash (mod n):", original_hash_mod)
    print("Decrypted Hash      :", decrypted_hash)

    if original_hash_mod == decrypted_hash:
        print("Match: Signature is VALID ✅")
    else:
        print("Mismatch: Signature is INVALID ❌")


# 🔁 User Input
message = input("Enter message: ")

signature = sign(message)
print("\nDigital Signature:", signature)

verify(message, signature)