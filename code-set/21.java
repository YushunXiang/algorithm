import java.util.Scanner;

/**
 * OJ
 * Dynamic Programming
 *
 * @author ysxiang
 */
class Main {
    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int inputValue = sn.nextInt();
        System.out.println(new Main().lastRemaining(inputValue));
    }

    /**
     * @param n        数组长度
     * @param fromLeft ture 从左到右，false从右到左
     * @return
     */
    public int recursion(int n, boolean fromLeft) {
        if (n == 1) {
            return 1;
        }
        if (fromLeft) {
            return 2 * recursion(n / 2, false); // 剩下的都是双数
        } else {
            if (n % 2 == 1) {
                return 2 * recursion(n / 2, true);
            } else {
                return 2 * recursion(n / 2, true) - 1;
            }
        }
    }

    public int lastRemaining(int n) {
        return recursion(n, true); // 先从左到右
    }
}