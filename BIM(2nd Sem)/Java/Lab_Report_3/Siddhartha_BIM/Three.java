// Define string array of size 10 and insert name of 10 student in in. Then list the name
// of students that ends with letter 'a'

public class Three {
    public static void main(String[] args) {
        // Declare string array of size 10
        String arr[] = {
                "Sinmbf",
                "Sameer",
                "Aman",
                "Tisha",
                "Subashree",
                "Divashree",
                "Soheb",
                "Abhishek",
                "Siddhartha",
                "Riya"
        };
        // Display students whose name end with 'a'
        System.out.println("Students whose name ends with \'a\':");
        for (int i = 0; i < arr.length; i++) {
            // Find last index of string
            int lastIndex = arr[i].length() - 1;
            // Find the last character
            char lastCharacter = arr[i].charAt(lastIndex);
            // Determine if last character is 'a'
            if (lastCharacter == 'a') {
                System.out.println(arr[i]);
            }
        }
    }
}
