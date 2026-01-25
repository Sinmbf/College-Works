// Create a String array that holds name of 5 birds and print the name of such birds whose
// first letter start with 's'.

public class Five {
    public static void main(String[] args) {
        // Declare and initialize string array
        String birdArr[] = {
                "sparrow",
                "pigeon",
                "parrot",
                "crow",
                "eagle"
        };
        // Display birds whose name start with 's'
        System.out.println("Birds whose name start with 's': ");
        for (int i = 0; i < birdArr.length; i++) {
            // Find first character
            char firstCharacter = birdArr[i].charAt(0);
            // Display bird whose name start with 's'
            if (firstCharacter == 's') {
                System.out.println(birdArr[i]);
            }
        }
    }
}
