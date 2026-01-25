// WAP to express GCD of 2 integer as linear combination of them using extended
// Euclidean algorithm.

#include <stdio.h>

int main() {
    int a, b, n1, n2, q, r, gcd;
    int s, t, s1, s2, t1, t2;
    
    printf("Enter the value of a and b: ");
    scanf("%d%d", &a, &b);
    
    n1 = a;
    n2 = b;
    
    if (b == 0) {
        gcd = a;
        s = 1;
        t = 0;
    } else {
        s1 = 1;
        s2 = 0;
        t1 = 0;
        t2 = 1;
        
        while (b > 0) {
            q = a / b;
            r = a % b;
            
            // Update the coefficients
            int temp_s = s2 - q * s1;
            int temp_t = t2 - q * t1;
            
            // Update a and b for the next iteration
            a = b;
            b = r;
            s2 = s1;
            s1 = temp_s;
            t2 = t1;
            t1 = temp_t;
        }
        
        gcd = a;
        s = s2;
        t = t2;
    }
    
    printf("GCD(%d, %d) is %d\n", n1, n2, gcd);
    printf("%d = (%d * %d) + (%d * %d)\n", gcd, s, n1, t, n2);
    
    return 0;
}

