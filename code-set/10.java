import java.util.*;

/**
 * @author ysxiang
 */
import java.util.*;

public class Main {
    public static void main(String arg[]) {
        Scanner snc =new Scanner(System.in);
        int n =snc.nextInt();
        Main main=new Main();
        System.out.println(main.convertToTitle(n));
    }

    public String convertToTitle(int columnNumber) {
        StringBuffer title = new StringBuffer();
        while (columnNumber > 0) {
            title.insert(0, String.valueOf((char) ((columnNumber - 1) % 26 + Integer.valueOf('A'))));
            columnNumber = (columnNumber - 1)/ 26;
        }
        return new String(title);
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