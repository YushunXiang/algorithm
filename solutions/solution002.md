# Problem 02 满足k的数对

``` java
import java.util.*;

public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);

        int n = snc.nextInt();
        int k = snc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = snc.nextInt();
        }
        System.out.println(k_dis(nums, k));
    }

    /**
     * 利用HashMap方法
     * @param nums
     * @param k
     * @return
     */
    public static int k_dis(int[] nums, int k) {
        int count = 0;
        int length = nums.length;
        HashMap<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
        for (int iter = 0; iter < length; iter++) {
            count += hashMap.getOrDefault( nums[iter] - k, 0) + hashMap.getOrDefault(nums[iter] + k, 0);
            hashMap.put(nums[iter], hashMap.getOrDefault(nums[iter], 0) + 1);
        }
        return count;
    }
}
```