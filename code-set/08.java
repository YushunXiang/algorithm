import java.util.*;

/**
 * @author ysxiang
 */
public class Main {

    private HashSet<String> hashSet = new HashSet<String>();

    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
        System.out.println(main.reorderedPowerOf2(n));
    }

    public boolean reorderedPowerOf2(int n) {
        for (int num = 1; num <= (int)1e9; num <<= 1) {
            hashSet.add(countDigits(num));
        }
        return hashSet.contains(countDigits(n));
    }

    public String countDigits(int num) {
        char[] countDigitsResult = new char[10];
        while (num > 0) {
            countDigitsResult[num % 10]++;
            num = num / 10;
        }
        return new String(countDigitsResult);
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