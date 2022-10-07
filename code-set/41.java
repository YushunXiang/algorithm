import java.util.Scanner;

/**
 * @author ysxiang
 */
import java.util.Scanner;

class Main {
    public int rob(int[] nums) {
        int numsLength = nums.length;
        int[] maxMoney = new int[100];
        maxMoney[0] = nums[0];
        maxMoney[1] = nums[1];
        maxMoney[2] = maxMoney[0] + nums[2];
        for (int iter = 3; iter < numsLength; iter++) {
            maxMoney[iter] = nums[iter] + Math.max(maxMoney[iter - 2], maxMoney[iter - 3]);
        }
        return (Math.max(maxMoney[numsLength - 1], maxMoney[numsLength - 2]));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = scanner.nextInt();
        }
        System.out.println(new Main().rob(ans));
    }
}