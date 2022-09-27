# Problem 06 连续整数求和

```java
mport java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
        System.out.println(main.consecutiveNumbersSum(n));
    }

    /**
     * 设连续数列首项为a，公差为1，共k项。
     * 有 ka + k * (k - 1) /2 = n
     * k ^ 2 + 2 * k * a- k = 2n
     * 2a = 2n/k - k + 1 >= 2
     * @param n
     * @return
     */
    public int consecutiveNumbersSum(int n) {
        int count = 0;
        int nMulti2 = n * 2;
        for (int k = 1; k * k < nMulti2; k++) {
            if (nMulti2 % k != 0) {
                continue;
            }
            if ((nMulti2 / k - k + 1) % 2 ==0) {
                count++;
            }
        }
        return count;
    }
}
```