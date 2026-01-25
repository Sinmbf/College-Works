// WAP to print 1 to 100 but skipping 25, 40 and 90

public class Eighteen {
    public static void main(String[] args) {
        for (int i = 1; i <= 100; i++) {
            if (i == 25 || i == 40 || i == 90) {
                continue;
            }
            System.out.print(i + " ");
        }
    }
}
