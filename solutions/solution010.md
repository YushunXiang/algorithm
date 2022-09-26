# Problem 10 找到对应的列名

``` java
import java.util.*;

/**
 * @author ysxiang
 */
import java.util.*;

public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
        System.out.println(main.convertToTitle(n));
    }

    public String convertToTitle(int columnNumber) {
        StringBuffer title = new StringBuffer();
        while (columnNumber > 0) {
            title.insert(0, String.valueOf((char) ((columnNumber - 1) % 26 + Integer.valueOf('A'))));
            columnNumber = (columnNumber - 1)/ 26;
        }
        return new String(title);
    }
}
```