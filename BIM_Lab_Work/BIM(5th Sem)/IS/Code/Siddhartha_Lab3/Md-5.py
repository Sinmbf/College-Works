import math

def left_rotate(x, c):
    return ((x << c) | (x >> (32 - c))) & 0xffffffff

def md5(message):
    message = bytearray(message, 'utf-8')
    orig_len = (8 * len(message)) & 0xffffffffffffffff

    message.append(0x80)
    while (len(message) * 8) % 512 != 448:
        message.append(0)
    message += orig_len.to_bytes(8, 'little')

    # Init
    A, B, C, D = 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476

    # Generate K dynamically
    K = [int(abs(math.sin(i + 1)) * (2**32)) & 0xffffffff for i in range(64)]

    # Shift amounts
    S = [7,12,17,22]*4 + [5,9,14,20]*4 + [4,11,16,23]*4 + [6,10,15,21]*4

    for i in range(0, len(message), 64):
        M = [int.from_bytes(message[i+j:i+j+4], 'little') for j in range(0, 64, 4)]
        a, b, c, d = A, B, C, D

        for j in range(64):
            if j < 16:
                f = (b & c) | (~b & d)
                g = j
            elif j < 32:
                f = (d & b) | (~d & c)
                g = (5*j + 1) % 16
            elif j < 48:
                f = b ^ c ^ d
                g = (3*j + 5) % 16
            else:
                f = c ^ (b | ~d)
                g = (7*j) % 16

            temp = (a + f + K[j] + M[g]) & 0xffffffff
            a, d, c, b = d, c, b, (b + left_rotate(temp, S[j])) & 0xffffffff

        A = (A + a) & 0xffffffff
        B = (B + b) & 0xffffffff
        C = (C + c) & 0xffffffff
        D = (D + d) & 0xffffffff

    return ''.join(f'{x:02x}' for x in A.to_bytes(4,'little') +
                                      B.to_bytes(4,'little') +
                                      C.to_bytes(4,'little') +
                                      D.to_bytes(4,'little'))


# Example
print(md5("hello"))