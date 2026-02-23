import secrets

def generate_key(length):
    """Generates a cryptographically strong random key of a given length."""
    # Using 'secrets' for better security than the 'random' module
    return secrets.token_bytes(length)

def vernam_cipher(text_bytes, key_bytes):
    """Encrypts or decrypts by XORing text bytes with key bytes."""
    return bytes(a ^ b for a, b in zip(text_bytes, key_bytes))

# --- Example Usage ---
message = "Hello everyone"
message_bytes = message.encode()

# 1. Generate a key of the exact same length as the message
key = generate_key(len(message_bytes))

# 2. Encrypt
ciphertext = vernam_cipher(message_bytes, key)
print(f"Ciphertext (hex): {ciphertext.hex()}")

# 3. Decrypt (XORing again with the same key restores the original)
decrypted_bytes = vernam_cipher(ciphertext, key)
print(f"Decrypted: {decrypted_bytes.decode()}")
