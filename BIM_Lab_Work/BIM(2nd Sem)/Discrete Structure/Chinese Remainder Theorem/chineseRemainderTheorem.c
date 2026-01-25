#include <stdio.h>

// Function to find the modular inverse of a modulo m
int inverse(int a, int m) {
    int q, r, s, t, s2, s1, t2, t1;
    s2 = 1;
    s1 = 0;
    t2 = 0;
    t1 = 1;
    
    while (m > 0) {
        q = a / m;
        r = a % m;
        s = s2 - q * s1;
        t = t2 - q * t1;
        a = m;
        m = r;
        s2 = s1;
        s1 = s;
        t2 = t1;
        t1 = t;
    }
    
    return s2;
}

int main() {
    int n, i;
    int a[5], m[5], M[5], y[5];
    int mp = 1, result = 0;

    printf("How many congruences in the system? ");
    scanf("%d", &n);

    printf("Enter %d simultaneous congruences:\n", n);
    for (i = 0; i < n; i++) {
        printf("For congruence %d:\n", i + 1);
        printf("Modulus m%d: ", i + 1);
        scanf("%d", &m[i]);
        printf("Residue a%d: ", i + 1);
        scanf("%d", &a[i]);
        mp *= m[i];
    }

    // Calculate M[i] and y[i]
    for (i = 0; i < n; i++) {
        M[i] = mp / m[i];
        y[i] = inverse(M[i], m[i]);
    }

    // Calculate the result
    for (i = 0; i < n; i++) {
        result += a[i] * M[i] * y[i];
    }

    result = result % mp;

    printf("The solution to the system of congruences is: %d\n", result);

    return 0;
}

