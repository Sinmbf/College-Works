// WAP to demonstrate all bitwise operator (for positive and negative number)

public class Six {
    public static void main(String[] args) {
        int positiveNum1 = 5; // Binary --> 0101
        int positiveNum2 = 4; // Binary --> 0101
        int negativeNum1 = -5; // Binary --> 0100
        int negativeNum2 = -4; // Binary --> 0101
        /*
         * For performing bitwise operation on negative number *
         * 1. Convert the given numbers into binary
         * 2. Find their 2's complement (1's complement + 1)
         * 3. Perform bitwise operation
         * 4. Again, convert the result into 2's complement (if first bit 1 then
         * negative)
         */
        // Bitwise AND
        System.out.println("Bitwise AND: " + (positiveNum1 & positiveNum2)); // 0101 & 0100 = 0100 (4)
        System.out.println("Bitwise AND: " + (negativeNum1 & negativeNum2));
        // Bitwise OR
        System.out.println("Bitwise OR: " + (positiveNum1 | positiveNum2));// 0101 | 0100 = 0101 (5)
        System.out.println("Bitwise OR: " + (negativeNum1 | negativeNum2));
        // Bitwise XOR
        System.out.println("Bitwise XOR: " + (positiveNum1 ^ positiveNum2)); // 0101 ^ 0100 = 0001 (1)
        System.out.println("Bitwise XOR: " + (negativeNum1 ^ negativeNum2));
        // Bitwise Complement
        System.out.println("Bitwise complement: " + (~positiveNum1)); // ~0101 = 1010 (-6)
        System.out.println("Bitwise complement: " + (~negativeNum1));
    }
}
