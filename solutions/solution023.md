# Problem 23 1出现了几次？

```java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String[] args) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
        System.out.println(main.countDigitOne(n));
    }

    /**
     * 计算1的个数
     * @param n
     * @return
     */
    public int countDigitOne(int n) {
        String nString = String.valueOf(n);
        int nLength = nString.length();
        if (nLength == 1) {
            if (n > 0) {
                return 1;
            } else {
                return 0;
            }
        }
        // 计算第i位前的数值，和第i位后的数值
        // 例如 abcde 则有 before[2] = ab; behind[2] = de
        int[] before = new int[nLength];
        int[] behind = new int[nLength];
        behind[0] = Integer.parseInt(nString.substring(1));
        for (int iter = 1; iter < nLength - 1; iter++) {
            before[iter] = Integer.parseInt(nString.substring(0, iter));
            behind[iter] = Integer.parseInt(nString.substring(iter + 1));
        }
        before[nLength - 1] = Integer.parseInt(nString.substring(0, nLength - 1));

        int digitOneCount = 0;
        for (int iter = 0; iter < nLength; iter++) {
            // x 为当前位数值，len 为当前位后面长度为多少
            int x = nString.charAt(iter) - '0';
            int len = nLength - iter - 1;
            int prefix = before[iter];
            int suffix = behind[iter];
            int total = 0;
            // 当 c 前面的部分小于 ab 时
            total += prefix * intPow10(len);
            if (x == 0) {

            } else if (x == 1) {
                total += suffix + 1;
            } else {
                total += intPow10(len);
            }
            digitOneCount += total;
        }
        return digitOneCount;
    }

    /**
     * 等价于 pow(10, index)
     * @param index
     * @return
     */
    public int intPow10 (int index) {
        if (index == 0) {
            return 1;
        } else {
            int powResult = 1;
            while (index > 0) {
                powResult *= 10;
                index--;
            }
            return powResult;
        }
    }
}
```