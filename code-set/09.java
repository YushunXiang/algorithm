import java.util.*;

public class Main {

    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = snc.nextInt();
        }
        Main main = new Main();
        System.out.println(main.maximumGap(arr));
    }

    public int maximumGap(int[] nums) {
            Arrays.sort(nums);
            int maxGap = 0;
            for (int iter = 0; iter < nums.length - 1; iter++) {
                if (nums[iter + 1] - nums[iter] > maxGap) {
                    maxGap = nums[iter + 1] - nums[iter];
                }
            }
            return maxGap;
    }
}


//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//