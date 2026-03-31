def left_rotate(n, b):
    return ((n << b) | (n >> (32 - b))) & 0xffffffff

def sha1(message):
    # Pre-processing
    message = bytearray(message, 'utf-8')  # convert to bytes
    original_bit_len = (8 * len(message)) & 0xffffffffffffffff
    
    # append the bit '1' to the message
    message.append(0x80)
    
    # append 0 <= k < 512 bits '0', so that the resulting message length is congruent to 448 mod 512
    while (len(message) * 8) % 512 != 448:
        message.append(0)
    
    # append original length in bits at the end of the buffer
    message += original_bit_len.to_bytes(8, byteorder='big')
    
    # Initial hash values
    h0 = 0x67452301
    h1 = 0xEFCDAB89
    h2 = 0x98BADCFE
    h3 = 0x10325476
    h4 = 0xC3D2E1F0
    
    # Process the message in successive 512-bit chunks
    for i in range(0, len(message), 64):
        chunk = message[i:i+64]
        
        # Break chunk into sixteen 32-bit big-endian words
        w = [int.from_bytes(chunk[j:j+4], 'big') for j in range(0, 64, 4)]
        
        # Extend the sixteen 32-bit words into eighty 32-bit words
        for j in range(16, 80):
            w.append(left_rotate(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1))
        
        # Initialize hash value for this chunk
        a, b, c, d, e = h0, h1, h2, h3, h4
        
        # Main loop
        for j in range(80):
            if 0 <= j <= 19:
                f = (b & c) | ((~b) & d)
                k = 0x5A827999
            elif 20 <= j <= 39:
                f = b ^ c ^ d
                k = 0x6ED9EBA1
            elif 40 <= j <= 59:
                f = (b & c) | (b & d) | (c & d)
                k = 0x8F1BBCDC
            else:
                f = b ^ c ^ d
                k = 0xCA62C1D6
            
            temp = (left_rotate(a, 5) + f + e + k + w[j]) & 0xffffffff
            e = d
            d = c
            c = left_rotate(b, 30)
            b = a
            a = temp
        
        # Add this chunk's hash to result so far
        h0 = (h0 + a) & 0xffffffff
        h1 = (h1 + b) & 0xffffffff
        h2 = (h2 + c) & 0xffffffff
        h3 = (h3 + d) & 0xffffffff
        h4 = (h4 + e) & 0xffffffff
    
    # Produce the final hash value (160-bit)
    return ''.join(f'{x:08x}' for x in [h0, h1, h2, h3, h4])


# Example usage
if __name__ == "__main__":
    text = input("Enter message: ")
    print("SHA-1 hash:", sha1(text))