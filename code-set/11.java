import java.util.*;

/**
 * @author ysxiang
 */

public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        int k = snc.nextInt();
        Main main = new Main();
        System.out.println(main.isNAPowerOfK(n, k));
    }

    public int isNAPowerOfK(int n, int k) {
        if (n < k) {
            if (n == 1) {
                return 1;
            } else {
                return 0;
            }
        } else if (n == k) {
            return 1;
        } else if (k == 1) {
            return 0;
        } else {
            for (int iter = k; iter <= n; iter *= k) {
                if (iter < n) {
                    continue;
                } else {
                    return 1;
                }
            }
            return 0;
        }
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