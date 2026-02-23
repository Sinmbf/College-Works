import string

def create_matrix(key):
    """Creates a 5x5 matrix using the provided key and the English alphabet."""
    key = key.upper().replace('J', 'I')
    alphabet = string.ascii_uppercase.replace('J', '')
    
    # Remove duplicate characters and preserve order
    combined = ""
    for char in key + alphabet:
        if char.isalpha() and char not in combined:
            combined += char
    
    # Reshape the string into a 5x5 grid (list of lists)
    return [list(combined[i:i+5]) for i in range(0, 25, 5)]

def prepare_text(text):
    """Formats text into digraphs (pairs), handling duplicates and odd lengths."""
    text = text.upper().replace('J', 'I').replace(" ", "")
    prepared = ""
    i = 0
    while i < len(text):
        prepared += text[i]
        if i + 1 < len(text):
            if text[i] == text[i+1]:
                # Insert 'X' if two consecutive letters are the same
                prepared += 'X'
            else:
                prepared += text[i+1]
                i += 1
        else:
            # Add 'X' if the total length is odd
            prepared += 'X'
        i += 1
    return prepared

def find_position(matrix, char):
    """Returns the row and column index of a character in the matrix."""
    for r, row in enumerate(matrix):
        if char in row:
            return r, row.index(char)

def playfair_cipher(text, key, mode='encrypt'):
    """Main logic for both Encryption and Decryption."""
    matrix = create_matrix(key)
    
    # Prepare text only for encryption; decryption text is already in pairs
    if mode == 'encrypt':
        text = prepare_text(text)
    
    result = ""
    # shift +1 for Encryption (Right/Down), -1 for Decryption (Left/Up)
    shift = 1 if mode == 'encrypt' else -1

    for i in range(0, len(text), 2):
        r1, c1 = find_position(matrix, text[i])
        r2, c2 = find_position(matrix, text[i+1])

        if r1 == r2: 
            # Rule 1: Same Row - shift horizontally
            result += matrix[r1][(c1 + shift) % 5] + matrix[r2][(c2 + shift) % 5]
        elif c1 == c2: 
            # Rule 2: Same Column - shift vertically
            result += matrix[(r1 + shift) % 5][c1] + matrix[(r2 + shift) % 5][c2]
        else: 
            # Rule 3: Rectangle - swap columns
            result += matrix[r1][c2] + matrix[r2][c1]
            
    return result

# --- Execution Example ---
my_key = "KEYWORD"
my_msg = "HELLO WORLD"

# Encrypt
ciphertext = playfair_cipher(my_msg, my_key, mode='encrypt')
print(f"Original Text: {my_msg}")
print(f"Encrypted: {ciphertext}")

# Decrypt
decrypted = playfair_cipher(ciphertext, my_key, mode='decrypt')
print(f"Decrypted: {decrypted}")
