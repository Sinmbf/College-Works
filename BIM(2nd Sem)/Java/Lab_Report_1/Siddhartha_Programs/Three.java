// WAP to describe floating point literals (exponential and normal), Boolean literals, character literals, string literals(uses of escape sequence)

public class Three {
    public static void main(String[]args){
        // Floating Point Literals
        double exponentialFloat=1.2040e2; // 1.2040 * 10^2
        double normalFloat=1.2;
        // Boolean Literals
        boolean trueLiteral=true;
        // Character Literals
        char ch='S';
        // String Literals with Escape Sequence
        String nextLine="I am\nSid";
        // Common Escape Sequences
        String backSlash="Backslash character: \\";
        String singleQuote="Single Quote character: \'";
        String doubleQuote="Double Quote character: \"\"";
        // Display
        System.out.println("Exponential Float: " + exponentialFloat);
        System.out.println("Normal Float "+ normalFloat);
        System.out.println("Boolean Literal: " + trueLiteral);
        System.out.println("Character Literal: " + ch);
        System.out.println("String Literals with Escape Sequence: ");
        System.out.println("Next Line Character: " + nextLine);
        System.out.println(backSlash);
        System.out.println(singleQuote);
        System.out.println(doubleQuote);
    }
}
