import math

def generate_k():
    primes = []
    num = 2
    
    # Get first 64 primes
    while len(primes) < 64:
        for p in primes:
            if num % p == 0:
                break
        else:
            primes.append(num)
        num += 1

    # Generate constants
    k = []
    for p in primes:
        frac = (p ** (1/3)) % 1   # fractional part of cube root
        k.append(int(frac * (2**32)) & 0xffffffff)

    return k


# SHA-256 implementation from scratch

def right_rotate(n, d):
    return (n >> d) | (n << (32 - d)) & 0xffffffff

def sha256(message):
    # Initialize hash values (first 32 bits of fractional parts of square roots of primes)
    h = [
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    ]

    # Round constants (first 32 bits of fractional parts of cube roots of primes)
    k = generate_k()

    # Pre-processing
    message = bytearray(message, 'utf-8')
    bit_len = len(message) * 8

    message.append(0x80)
    while (len(message) * 8) % 512 != 448:
        message.append(0)

    message += bit_len.to_bytes(8, 'big')

    # Process 512-bit chunks
    for i in range(0, len(message), 64):
        chunk = message[i:i+64]

        # Create message schedule
        w = [int.from_bytes(chunk[j:j+4], 'big') for j in range(0, 64, 4)]

        for j in range(16, 64):
            s0 = (right_rotate(w[j-15], 7) ^
                  right_rotate(w[j-15], 18) ^
                  (w[j-15] >> 3))
            s1 = (right_rotate(w[j-2], 17) ^
                  right_rotate(w[j-2], 19) ^
                  (w[j-2] >> 10))
            w.append((w[j-16] + s0 + w[j-7] + s1) & 0xffffffff)

        a, b, c, d, e, f, g, h_val = h

        # Main compression loop
        for j in range(64):
            S1 = (right_rotate(e, 6) ^
                  right_rotate(e, 11) ^
                  right_rotate(e, 25))
            ch = (e & f) ^ ((~e) & g)
            temp1 = (h_val + S1 + ch + k[j] + w[j]) & 0xffffffff

            S0 = (right_rotate(a, 2) ^
                  right_rotate(a, 13) ^
                  right_rotate(a, 22))
            maj = (a & b) ^ (a & c) ^ (b & c)
            temp2 = (S0 + maj) & 0xffffffff

            h_val = g
            g = f
            f = e
            e = (d + temp1) & 0xffffffff
            d = c
            c = b
            b = a
            a = (temp1 + temp2) & 0xffffffff

        # Update hash values
        h = [
            (h[0] + a) & 0xffffffff,
            (h[1] + b) & 0xffffffff,
            (h[2] + c) & 0xffffffff,
            (h[3] + d) & 0xffffffff,
            (h[4] + e) & 0xffffffff,
            (h[5] + f) & 0xffffffff,
            (h[6] + g) & 0xffffffff,
            (h[7] + h_val) & 0xffffffff
        ]

    return ''.join(f'{value:08x}' for value in h)


# Example usage
if __name__ == "__main__":
    text = input("Enter message: ")
    print("SHA-2 hash:", sha256(text))