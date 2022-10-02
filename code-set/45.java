import java.util.Scanner;

/**
 * OJ
 * Dynamic Programming
 * @author ysxiang
 */
class Main {
    public static int longestSubsequence(int[] arr, int difference) {
        int arrLength = arr.length;
        int[] dp = new int[arrLength];
        int maxLength = 0;
        for (int i = 0; i < arrLength; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] - arr[j] == difference) {
                    dp[i] = dp[j] + 1;
                    maxLength = Math.max(maxLength, dp[i]);
                }
            }
        }
        return maxLength + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int difference = scanner.nextInt();
        System.out.println(longestSubsequence(arr,difference));
    }
}