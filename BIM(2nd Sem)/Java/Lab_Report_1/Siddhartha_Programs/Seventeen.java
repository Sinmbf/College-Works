// WAP to demonstrate use of break and continue

public class Seventeen {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            if (i == 5) {
                continue; // Skip iteration when i=5
            }
            if (i == 8) {
                break; // exit the loop when i=8
            }
            System.out.println(i);
        }
    }
}
