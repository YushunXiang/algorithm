import java.util.Scanner;

/**
 * @author ysxiang
 */
class Main {

    public int specialSection(int[] nums, int lower, int upper) {
        int numsLength = nums.length;
        int sectionNumber = 0; // 符合要求区间的个数
        int sectionSum = 0; // 区间内的数字和
        for (int i = 0; i < numsLength; i++) {
            for (int j = i; j < numsLength; j++) {
                sectionSum += nums[j];
                if (sectionSum >= lower && sectionSum <= upper) {
                    sectionNumber++;
                }
            }
            sectionSum = 0;
        }
        return sectionNumber;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        String arr[] = str.split(" ");
        int[] nums = new int[arr.length];
        for (int iter = 0; iter < nums.length; iter++) {
            nums[iter] = Integer.parseInt(arr[iter]);
        }
        int lower = scanner.nextInt();
        int upper = scanner.nextInt();
        System.out.println(new Main().specialSection(nums, lower, upper));
    }
}