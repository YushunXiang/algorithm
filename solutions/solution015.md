# Problem 15 运算结果

## Solution

```java
import java.util.Scanner;
import java.util.Stack;

/**
 * OJ
 *
 * @author ysxiang
 */
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        System.out.println(new Main().calculateResult(str.toCharArray()));
    }

    /**
     * Calculate the result.
     * @param chars
     */
    public char calculateResult(char[] chars) {
        Stack<Character> stack = new Stack<>();
        int charsLength = chars.length;
        for (int iter = charsLength - 1; iter >= 0; iter--) {
            if (chars[iter] == ':') {
                stack.push(chars[--iter]);
            } else if (chars[iter] == '?') {
                char temp = stack.pop();
                if (chars[--iter] == 'T') {
                    stack.pop();
                    stack.push(temp);
                }
            } else {
                stack.push(chars[iter]);
            }
        }
        return stack.peek();
    }
}
```