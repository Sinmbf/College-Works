// WAP to demonstrate six string methods

public class StringMethod {
    public static void main(String[]args){
        String str="Hello World";
        // Method 1: str.length() => returns the length of the string
        System.out.println("Length of the string: " + str.length());
        // Method 2: str.toUpperCase() => converts the string into uppercase
        System.out.println("Into uppercase: " + str.toUpperCase());
        // Method 3: str.toLowerCase() => converts the string into lowercase
        System.out.println("Into lowercase: " + str.toLowerCase());
        // Method 4: str.charAt(index) => returns the character at the given index
        System.out.println("Character at index 0: " + str.charAt(0));
        // Method 5: str.replace(char 1,char 2) => Replaces all occurrences of a specified character
        // with a new character.
        System.out.println("'Hello World' replaced by another string: " + str.replace(str,"Hello Sinmbf"));
        // Method 6: str.substring(int beginIndex, int endIndex) => returns a new string that is
        // a substring of this string
        System.out.println("Substring from index 6 to 9: " + str.substring(6,9));
    }    
}
