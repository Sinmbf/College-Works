// WAP to demonstrate all bitwise operator (for positive and negative number)

public class Six {
    public static void main(String[] args) {
        // For Positive Integer
        int n1 = 5; // Binary --> 0101
        int n2 = 4; // Binary --> 0100
        // Bitwise AND
        int res = n1 & n2;
        System.out.println(res); // 0101 & 0100 = 0100 (4)
        // Bitwise OR
        res = n1 | n2;
        System.out.println(res); // 0101 | 0100 = 0101 (5)
        // Bitwise XOR
        res = n1 ^ n2;
        System.out.println(res); // 0101 ^ 0100 = 0001 (1)
        // Bitwise Complement
        res = ~n1;
        System.out.println(res); // ~0101 = 1010 (-6)
    }
}
