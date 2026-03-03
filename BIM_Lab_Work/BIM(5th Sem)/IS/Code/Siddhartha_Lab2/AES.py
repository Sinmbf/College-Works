from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import base64
import os

# Generate random 16-byte key
key = os.urandom(16)

def encrypt_message(message, key):
    iv = os.urandom(16)  # New IV every time (important!)
    cipher = AES.new(key, AES.MODE_CBC, iv)

    padded_message = pad(message.encode(), AES.block_size)
    ciphertext = cipher.encrypt(padded_message)

    return base64.b64encode(iv + ciphertext).decode()


def decrypt_message(ciphertext, key):
    raw_data = base64.b64decode(ciphertext)

    iv = raw_data[:16]
    cipher = AES.new(key, AES.MODE_CBC, iv)

    decrypted_text = unpad(cipher.decrypt(raw_data[16:]), AES.block_size)
    return decrypted_text.decode()


# ===== RUN =====
message = "My name is Siddhartha"

encrypted_msg = encrypt_message(message, key)
decrypted_msg = decrypt_message(encrypted_msg, key)

print("Encrypted:", encrypted_msg)
print("Decrypted:", decrypted_msg)