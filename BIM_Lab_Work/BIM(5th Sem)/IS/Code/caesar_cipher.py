def caesar_encrypt(text, shift):
    """
    Encrypts a message using the Caesar cipher.
    Handles both uppercase and lowercase letters, and preserves other characters.
    """
    result = ""
    for char in text:
        if char.isalpha():
            # Determine the base ASCII value ('A' or 'a')
            base = ord('A') if char.isupper() else ord('a')
            # Apply the shift using modular arithmetic to wrap around the alphabet
            shifted = (ord(char) - base + shift) % 26 + base
            result += chr(shifted)
        else:
            # Append non-alphabetic characters without change
            result += char
    return result

def caesar_decrypt(text, shift):
    # Decryption is just encryption with a negative shift
    return caesar_encrypt(text, -shift)

# Example Usage:
plaintext = "Hello, World!"
key = 3
encrypted_message = caesar_encrypt(plaintext, key)
print(f"Plaintext: {plaintext}")
print(f"Shift Key: {key}")
print(f"Encrypted: {encrypted_message}")
# Example Usage:
decrypted_message = caesar_decrypt(encrypted_message, key)
print(f"Decrypted: {decrypted_message}")
