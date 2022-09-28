# Problem 22 算一个斐波那契数列吧

```java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String[] args) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(getFibonacci(n));
    }

    public static int getFibonacci(int n) {
        int H0 = 0, H1 = 1;
        for (int iter = 0; iter < n / 2; iter++) {
            int temp0 = H0 + H1;
            int temp1 = temp0 + H1;
            H0 = temp0;
            H1 = temp1;
        }
        switch (n % 2) {
            case 0:
                return H0;
            case 1:
                return H1;
            default:
                return -1;
        }
    }
}
```