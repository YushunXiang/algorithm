# Problem 45 找等差数列

``` java
import java.util.Scanner;

/**
 * @author ysxiang
 */
class Main {
    public static int longestSubsequence(int[] arr, int difference) {
        int maxLength = 1;
        int length = 1;
        for (int iter = 0; iter < arr.length - 1; iter++) {

            if (arr[iter + 1] - arr[iter] == difference) {
                length++;
            } else {
                if (length > maxLength) {
                    maxLength = length;
                }
                length = 1;
            }
        }
        if (length > maxLength) {
            maxLength = length;
        }
        if (maxLength == 1) {
            return 0;
        } else {
            return maxLength;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int difference = scanner.nextInt();
        System.out.println(longestSubsequence(arr, difference));
    }
}
```