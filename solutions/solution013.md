# Problem 13 前n项和

```java
import java.util.*;

public class Main {

    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();

        Main main = new Main();
        System.out.println(main.addSumOfN(n));
    }

    public int addSumOfN(int n) {
        return (1 + n) * n / 2;
    }
}
```