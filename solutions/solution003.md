# Problem 03 一共存了多少钱

```java
import java.util.*;

public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(totalMoney(n));
    }

    public static int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        int total = 0;
        total = 28 * week + week * (week - 1) * 7 / 2;
        for (int iter = 0; iter < day; iter++) {
            total += week + iter + 1;
        }
        return total;
    }
}
```