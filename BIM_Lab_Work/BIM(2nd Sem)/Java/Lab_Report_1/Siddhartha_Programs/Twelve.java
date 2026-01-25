// WAP to print even numbers between 300 to 500

public class Twelve {
    public static void main(String[] args) {
        System.out.println("Even numbers between 300 - 500: ");
        for (int i = 301; i < 500; i++) {
            if (i % 2 == 0) {
                System.out.print(i + " ");
            }
        }
    }
}
