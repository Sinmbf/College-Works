// WAP to print prime number between 1 to 100

public class Eleven {
    public static void main(String[] args) {
        System.out.println("Prime numbers from 1 to 100:");
        for (int i = 1; i <= 100; i++) {
            boolean isPrime = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (i != 1 && isPrime) {
                System.out.print(i + " ");
            }
        }
    }
}
