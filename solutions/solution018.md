# Problem 18 真还是假？

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
        System.out.println(new Main().trueOrFalse(str.toCharArray()));
    }

    /**
     * judge expression is true or false.
     *
     * @param chars 字符数组
     */
    public int trueOrFalse(char[] chars) {
        Stack<Character> numbers = new Stack<>();
        Stack<Character> operations = new Stack<>();
        for (char charIter : chars) {
            switch (charIter) {
                case '|':
                case '&':
                case '!':
                    operations.push(charIter);
                    break;
                case 't':
                case 'f':
                case '(':
                    numbers.push(charIter);
                    break;
                case ')':
                    boolean tempFlag = false;
                    char number;
                    switch (operations.pop()) {
                        case '|':
                            tempFlag = false;
                            while ((number = numbers.pop()) != '(') {
                                tempFlag |= (number == 't');
                            }
                            numbers.push(tempFlag ? 't' : 'f');
                            break;
                        case '&':
                            tempFlag = true;
                            while ((number = numbers.pop()) != '(') {
                                tempFlag &= (number == 't');
                            }
                            numbers.push(tempFlag ? 't' : 'f');
                            break;
                        case '!':
                            while ((number = numbers.pop()) != '(') {
                                tempFlag = (number != 't');
                            }
                            numbers.push(tempFlag ? 't' : 'f');
                            break;
                    }
                default:
                    break;
            }
        }

        if (numbers.pop() == 't') {
            return 1;
        } else {
            return 0;
        }
    }
}
```