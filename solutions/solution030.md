# Problem 30 快乐数列

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.print(new Main().getResult(n));
    }

    public String getResult(int n) {
        if (n == 1) {
            return "1";
        } else if (n == 2) {
            return "11";
        }
        String str = String.valueOf(11);
        int prefix = 0, suffix = 0;
        int count = 1;
        for (int iter = 2; iter < n; iter++) {
            String tempStr = "";
            for (int index = 1; index < str.length(); index++) {
                prefix = Integer.parseInt(str.substring(index - 1, index));
                suffix = Integer.parseInt(str.substring(index, index + 1));
                if (prefix == suffix) {
                    count++;
                } else {
                    tempStr += String.valueOf(count) + String.valueOf(prefix);
                    count = 1;
                }
            }
            prefix = Integer.parseInt(str.substring(str.length() - 1, str.length()));
            tempStr += String.valueOf(count) + String.valueOf(prefix);
            str = tempStr;
            count = 1;
        }
        return str;
    }
}
```
