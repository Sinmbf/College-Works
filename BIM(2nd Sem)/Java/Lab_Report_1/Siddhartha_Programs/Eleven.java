// WAP to print prime number between 1 to 100

public class Eleven {
    public static void main(String[] args) {
        boolean isPrime = true;
        System.out.println("Prime numbers from 1 to 100:");
        for (int i = 1; i <= 100; i++) {
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                System.out.print(i + " ");
            }
            isPrime = true;
        }
    }
}
