import java.util.Scanner;

/**
 * @author ysxiang
 */
class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        System.out.println(new Main().isPowerOfFour(n));
    }

    public boolean isPowerOfFour(int number) {
        if (number == 1) {
            return true;
        }
        int result = 4;
        for (; result < number; result *= 4) {

        }
        if (result == number) {
            return true;
        }
        return false;
    }
}