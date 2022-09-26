# Problem 12 类菲波拉契数

```java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String[] args) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(Hibonacci(n));
    }

    public static int Hibonacci(int n) {
        int H0 = 0, H1 = 1, H2 = 1;
        for (int iter = 0; iter < n / 3; iter++) {
            int temp0 = H0 + H1 + H2;
            int temp1 = temp0 + H1 + H2;
            int temp2 = temp0 + temp1 + H2;
            H0 = temp0;
            H1 = temp1;
            H2 = temp2;
        }
        switch (n % 3) {
            case 0:
                return H0;
            case 1:
                return H1;
            case 2:
                return H2;
            default:
                return -1;
        }
    }
}
```