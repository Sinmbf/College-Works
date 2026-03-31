def left_rotate(x, n):
    return ((x << n) | (x >> (32 - n))) & 0xffffffff

def md4(message):
    # Pre-processing
    message = bytearray(message, 'utf-8')
    orig_len = (8 * len(message)) & 0xffffffffffffffff
    
    message.append(0x80)
    while (len(message) * 8) % 512 != 448:
        message.append(0)
    
    message += orig_len.to_bytes(8, 'little')

    # Initial values
    A, B, C, D = 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476

    # Functions
    F = lambda x, y, z: (x & y) | (~x & z)
    G = lambda x, y, z: (x & y) | (x & z) | (y & z)
    H = lambda x, y, z: x ^ y ^ z

    # Process blocks
    for i in range(0, len(message), 64):
        X = [int.from_bytes(message[i+j:i+j+4], 'little') for j in range(0, 64, 4)]
        AA, BB, CC, DD = A, B, C, D

        # Round 1
        S = [3, 7, 11, 19]
        for j in range(16):
            k = j
            s = S[j % 4]
            A = left_rotate((A + F(B, C, D) + X[k]) & 0xffffffff, s)
            A, B, C, D = D, A, B, C

        # Round 2
        S = [3, 5, 9, 13]
        for j in range(16):
            k = (j % 4) * 4 + j // 4
            s = S[j % 4]
            A = left_rotate((A + G(B, C, D) + X[k] + 0x5a827999) & 0xffffffff, s)
            A, B, C, D = D, A, B, C

        # Round 3
        S = [3, 9, 11, 15]
        order = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
        for j in range(16):
            k = order[j]
            s = S[j % 4]
            A = left_rotate((A + H(B, C, D) + X[k] + 0x6ed9eba1) & 0xffffffff, s)
            A, B, C, D = D, A, B, C

        A = (A + AA) & 0xffffffff
        B = (B + BB) & 0xffffffff
        C = (C + CC) & 0xffffffff
        D = (D + DD) & 0xffffffff

    return ''.join(f'{x:02x}' for x in A.to_bytes(4, 'little') +
                                      B.to_bytes(4, 'little') +
                                      C.to_bytes(4, 'little') +
                                      D.to_bytes(4, 'little'))


# Example
print(md4("Sidd"))