
## Problem 11 n = k^x ? （n是k的幂吗）

```java
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
        System.out.println(main.isNAPowerOfK(n, k));
    }

    public int isNAPowerOfK(int n, int k) {
        if (n < k) {
            if (n == 1) {
                return 1;
            } else {
                return 0;
            }
        } else if (n == k) {
            return 1;
        } else {
            for (int iter = k; iter <= n; iter *= k) {
                if (iter < n) {
                    continue;
                } else {
                    return 1;
                }
            }
            return 0;
        }
    }
}
```