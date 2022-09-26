# Problem 14 归一次数

``` java
import java.util.Scanner;

/**
 * @author ysxiang
 */
class Main {
    public static int backOne(int n) {
        if (n == 1) {
            return 0;
        } else {
            if (n % 2 == 0) {
                return backOne(n / 2) + 1;
            } else {
                int biggerOne = backOne(n + 1) + 1;
                int smallerOne = backOne(n - 1) + 1;
                if (biggerOne > smallerOne) {
                    return smallerOne;
                } else {
                    return biggerOne;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(backOne(n));
    }
}
```