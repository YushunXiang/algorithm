# Problem 20 英文读数

```java
import java.util.Scanner;

/**
 * @author ysxiang
 */
class Main {
    public final static int N_MAX = 2_000_000_000;
    public final static String[] singles = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    public final static String[] teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    public final static String[] tens = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    public final static String[] thousands = {"", "Thousand", "Million", "Billion"};

    public void recursion(StringBuffer currentStr, int num) {
        if (num == 0) {
            return;
        } else if (num < 10) {
            currentStr.append(singles[num - 1]).append(" ");
        } else if (num < 20) {
            currentStr.append(teens[num - 10]).append(" ");
        } else if (num < 100) {
            currentStr.append(tens[num / 10 - 1]).append(" ");
            recursion(currentStr, num % 10);
        } else {
            currentStr.append(singles[num / 100 - 1]).append(" Hundred ");
            recursion(currentStr, num % 100);
        }
    }


    public String translateNumber (int num) {
        if(num == 0) {
            return "Zero";
        }
        StringBuffer sb = new StringBuffer();
        for (int i = 3, unit = 1_000_000_000; i >= 0; i--, unit /= 1000) {
            int currentNum = num / unit;
            if (currentNum != 0) {
                num -= currentNum * unit;
                StringBuffer currentStr = new StringBuffer();
                recursion(currentStr, currentNum);
                currentStr.append(thousands[i]).append(" ");
                sb.append(currentStr);
            }
        }
        return sb.toString().trim();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        System.out.println(new Main().translateNumber(num));
    }
}
```