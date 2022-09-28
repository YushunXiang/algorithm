import java.util.*;

/**
 * @author ysxiang
 */
public class Main {

    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        int k = snc.nextInt();
        Main main = new Main();
        System.out.println(main.minimumNumbers(n, k));
    }

    public int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        } else {
            for (int iter = 1; iter <= 10; iter++) {
                if (iter * k <= num && (num - iter * k) % 10 == 0) {
                    return iter;
                }
            }
            return -1;
        }
    }
}