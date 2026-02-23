def encrypt_rail_fence(text, rails):
    if rails == 1: return text
    
    # Create empty rails
    fence = ['' for _ in range(rails)]
    rail = 0
    direction = 1  # 1 for down, -1 for up

    for char in text:
        fence[rail] += char
        rail += direction
        
        # Reverse direction at top or bottom rail
        if rail == 0 or rail == rails - 1:
            direction *= -1
            
    return "".join(fence)

def decrypt_rail_fence(cipher, rails):
    if rails == 1: return cipher
    
    # 1. Determine the zigzag pattern (positions)
    pattern = [None] * len(cipher)
    idx_map = []
    rail, direction = 0, 1
    
    # Track which rail each index of the original text belongs to
    for i in range(len(cipher)):
        idx_map.append((rail, i))
        rail += direction
        if rail == 0 or rail == rails - 1:
            direction *= -1
    
    # 2. Sort to find where each cipher character goes in the original string
    # Sorting by rail simulates reading the fence row-by-row
    idx_map.sort()
    
    result = [None] * len(cipher)
    for i in range(len(cipher)):
        # Fill the original positions with characters from the cipher
        original_pos = idx_map[i][1]
        result[original_pos] = cipher[i]
        
    return "".join(result)

# --- Example ---
message = "HELLOWORLD"
key = 3
encrypted = encrypt_rail_fence(message, key)
decrypted = decrypt_rail_fence(encrypted, key)

print(f"Original:  {message}")
print(f"Encrypted: {encrypted}")  # Output: HOLELWRLDO
print(f"Decrypted: {decrypted}")
