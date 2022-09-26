# Problem 28 二进制的第K位

```java
import java.util.Scanner;

/**
 * @author ysxiang
 */
public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        System.out.print(new Main().getResult(n, k));
    }

    /**
     * 递归
     * @param n
     * @param k
     * @return
     */
    public int getResult(int n, int k) {
        if (n == 1 && k == 1) {
            return 0;
        }
        int middle = 1 << (n - 1); // 2 ^ (n - 1)
        if (k == middle) {
            return 1;
        } else if (k < middle) {
            return getResult(n - 1, k);
        } else {
            k = (middle << 1) - k;
            return invert(getResult(n - 1, k));
        }
    }

    public int invert(int var) {
        return 1 - var;
    }
}
```