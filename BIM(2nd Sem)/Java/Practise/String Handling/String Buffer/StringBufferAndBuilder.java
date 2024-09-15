// WAP to demonstrate string builder and string buffer methods (Both methods same)

public class StringBufferAndBuilder {
    public static void main(String[]args){
        StringBuffer s1=new StringBuffer("Hello Sinmbf");
        // Method 1: append(String str) => Adds the specified string to the end 
        // of the existing sequence.
        s1.append(" Lost");
        System.out.println("Appended string: " + s1);
        // Method 2: insert(int offset, String str) => Inserts the specified string at
        // the specified index position.
        s1.insert(0,"S");
        System.out.println("After inserting string: " + s1);
        // Method 3: replace(int start, int end, String str) =>  Replaces the characters in the 
        // specified range with the given string.                                                                                     
        s1.replace(0,2,"Pe");
        System.out.println("After replacing string: " + s1);
        // Method 4: delete(int start, int end) => Removes the characters in the specified range.
        s1.delete(0,1);
        System.out.println("After deleting string: " + s1);
        // Method 5: reverse() => Reverses the sequence of characters.
        s1.reverse();
        System.out.println("After reversing string: " + s1);
    }    
}
