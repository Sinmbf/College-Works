// WAP to describe different literals (positive integer literals, negative integer literals, hexadecimal representation, octal, binary, etc )

public class Two {
    public static void main(String[]args){
        // Integer Literals
        int positiveInt=100; 
        // Negative Literals
        int negativeInt=-100; 
        // Hexadecimal Literals
        int hexInt=0x5A; 
        // Octal Literals
        int octalInt=012; 
        // Binary Literals
        int binaryInt=0b1101; 
        System.out.println("Positive Integer Literal: " + positiveInt);
        System.out.println("Negative Integer Literal: " + negativeInt);
        System.out.println("Hexadecimal Literal: " + hexInt);
        System.out.println("Octal Literal: " + octalInt);
        System.out.println("Binary Literal: " + binaryInt);
    }
}
