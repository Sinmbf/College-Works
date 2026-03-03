from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

# DES requires an 8-byte (64-bit) key
key = get_random_bytes(8)

def des_encrypt(plaintext, key):
    cipher = DES.new(key, DES.MODE_ECB)  # Using ECB mode for simplicity
    padded_text = pad(plaintext.encode(), DES.block_size)
    ciphertext = cipher.encrypt(padded_text)
    return ciphertext

def des_decrypt(ciphertext, key):
    cipher = DES.new(key, DES.MODE_ECB)
    decrypted_padded = cipher.decrypt(ciphertext)
    decrypted = unpad(decrypted_padded, DES.block_size)
    return decrypted.decode()

# --- Example Usage ---
message = "HelloSinmbf"

# Encrypt
ciphertext = des_encrypt(message, key)
print("Ciphertext (hex):", ciphertext.hex())

# Decrypt
decrypted_text = des_decrypt(ciphertext, key)
print("Decrypted Text:", decrypted_text)
