# Algorithm

[TOC]

**写在前面**

``` java
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
```



## Problem 01 最有意义的值h

``` java
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
        System.out.println(main.hIndex1(arr));
    }

    /**
     * method 1: 排序
     * @param citations
     * @return
     */
    public int hIndex1(int[] citations) {

        Arrays.sort(citations);
        int iter = citations.length - 1;
        int hIndex = 0;
        while (iter >= 0 && citations[iter] > hIndex) { // 如果citations[iter] > hIndex，则说明第iter + 1篇论文的引用数大于 h，符合条件，继续往下搜索。
            hIndex++;
            iter--;
        }
        return hIndex;
    }
}
```



## Problem 02 满足k的数对

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



## Problem 03 一共存了多少钱

``` java
import java.util.*;

public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(totalMoney(n));
    }

    public static int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        int total = 0;
        total = 28 * week + week * (week - 1) * 7 / 2;
        for (int iter = 0; iter < day; iter++) {
            total += week + iter + 1;
        }
        return total;
    }
}
```



## Problem 04 拆分正偶数

``` java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {

    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(maximumEvenSplit(n));
    }

    public static List<Long> maximumEvenSplit(long finalSum) {
        ArrayList<Long> list = new ArrayList<Long>();
        if (finalSum % 2 == 0) {
            long base = 2;
            list.add(base);
            finalSum = finalSum - 2;
            while (list.get(list.size() - 1) < finalSum) {
                base = base + 2;
                finalSum = finalSum - base;
                list.add(base);
            }
            list.set(list.size() - 1, list.get(list.size() - 1) + finalSum);
        }
        return list;
    }
}
```



## Problem 05 多少个数字1

``` java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String[] args) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
        System.out.println(main.countDigitOne(n));
    }

    /**
     * 计算1的个数
     * @param n
     * @return
     */
    public int countDigitOne(int n) {
        String nString = String.valueOf(n);
        int nLength = nString.length();
        if (nLength == 1) {
            if (n > 0) {
                return 1;
            } else {
                return 0;
            }
        }
        // 计算第i位前的数值，和第i位后的数值
        // 例如 abcde 则有 before[2] = ab; behind[2] = de
        int[] before = new int[nLength];
        int[] behind = new int[nLength];
        behind[0] = Integer.parseInt(nString.substring(1));
        for (int iter = 1; iter < nLength - 1; iter++) {
            before[iter] = Integer.parseInt(nString.substring(0, iter));
            behind[iter] = Integer.parseInt(nString.substring(iter + 1));
        }
        before[nLength - 1] = Integer.parseInt(nString.substring(0, nLength - 1));

        int digitOneCount = 0;
        for (int iter = 0; iter < nLength; iter++) {
            // x 为当前位数值，len 为当前位后面长度为多少
            int x = nString.charAt(iter) - '0';
            int len = nLength - iter - 1;
            int prefix = before[iter];
            int suffix = behind[iter];
            int total = 0;
            // 当 c 前面的部分小于 ab 时
            total += prefix * intPow10(len);
            if (x == 0) {

            } else if (x == 1) {
                total += suffix + 1;
            } else {
                total += intPow10(len);
            }
            digitOneCount += total;
        }
        return digitOneCount;
    }

    /**
     * 等价于 pow(10, index)
     * @param index
     * @return
     */
    public int intPow10 (int index) {
        if (index == 0) {
            return 1;
        } else {
            int powResult = 1;
            while (index > 0) {
                powResult *= 10;
                index--;
            }
            return powResult;
        }
    }
}
```



## Problem 06 连续整数求和

``` java
mport java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
        System.out.println(main.consecutiveNumbersSum(n));
    }

    /**
     * 设连续数列首项为a，公差为1，共k项。
     * 有 ka + k * (k - 1) /2 = n
     * k ^ 2 + 2 * k * a- k = 2n
     * 2a = 2n/k - k + 1 >= 2
     * @param n
     * @return
     */
    public int consecutiveNumbersSum(int n) {
        int count = 0;
        int nMulti2 = n * 2;
        for (int k = 1; k * k < nMulti2; k++) {
            if (nMulti2 % k != 0) {
                continue;
            }
            if ((nMulti2 / k - k + 1) % 2 ==0) {
                count++;
            }
        }
        return count;
    }
}
```



## Problem 07 个位数之和

``` java
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
        System.out.println(main.minimumNumbers(n, k));
    }

    public int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        } else {
            for (int iter = 1; iter <= 10; iter++) {
                if (iter * k <= num && (num - iter * k) % 10 == 0) {
                    return iter;
                }
            }
            return -1;
        }
    }
}
```



## Problem 08 2的幂

``` java
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
```



## Problem 09 数组间的最大距离

``` java
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
```



## Problem 10 找到对应的列名

``` java
import java.util.*;

/**
 * @author ysxiang
 */
import java.util.*;

public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
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
```



## Problem 11 n = k^x ? （n是k的幂吗）

``` java
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
```



## Problem 12 类菲波拉契数

```java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String[] args) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(Hibonacci(n));
    }

    public static int Hibonacci(int n) {
        int H0 = 0, H1 = 1, H2 = 1;
        for (int iter = 0; iter < n / 3; iter++) {
            int temp0 = H0 + H1 + H2;
            int temp1 = temp0 + H1 + H2;
            int temp2 = temp0 + temp1 + H2;
            H0 = temp0;
            H1 = temp1;
            H2 = temp2;
        }
        switch (n % 3) {
            case 0:
                return H0;
            case 1:
                return H1;
            case 2:
                return H2;
            default:
                return -1;
        }
    }
}
```



## Problem 13 前n项和

``` java
import java.util.*;

public class Main {

    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();

        Main main = new Main();
        System.out.println(main.addSumOfN(n));
    }

    public int addSumOfN(int n) {
        return (1 + n) * n / 2;
    }
}
```



## Problem 22 算一个斐波那契数列吧

``` java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String[] args) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(getFibonacci(n));
    }

    public static int getFibonacci(int n) {
        int H0 = 0, H1 = 1;
        for (int iter = 0; iter < n / 2; iter++) {
            int temp0 = H0 + H1;
            int temp1 = temp0 + H1;
            H0 = temp0;
            H1 = temp1;
        }
        switch (n % 2) {
            case 0:
                return H0;
            case 1:
                return H1;
            default:
                return -1;
        }
    }
}
```



## Problem 23 1出现了几次？

``` java
import java.util.*;

/**
 * @author ysxiang
 */
public class Main {
    public static void main(String[] args) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        Main main = new Main();
        System.out.println(main.countDigitOne(n));
    }

    /**
     * 计算1的个数
     * @param n
     * @return
     */
    public int countDigitOne(int n) {
        String nString = String.valueOf(n);
        int nLength = nString.length();
        if (nLength == 1) {
            if (n > 0) {
                return 1;
            } else {
                return 0;
            }
        }
        // 计算第i位前的数值，和第i位后的数值
        // 例如 abcde 则有 before[2] = ab; behind[2] = de
        int[] before = new int[nLength];
        int[] behind = new int[nLength];
        behind[0] = Integer.parseInt(nString.substring(1));
        for (int iter = 1; iter < nLength - 1; iter++) {
            before[iter] = Integer.parseInt(nString.substring(0, iter));
            behind[iter] = Integer.parseInt(nString.substring(iter + 1));
        }
        before[nLength - 1] = Integer.parseInt(nString.substring(0, nLength - 1));

        int digitOneCount = 0;
        for (int iter = 0; iter < nLength; iter++) {
            // x 为当前位数值，len 为当前位后面长度为多少
            int x = nString.charAt(iter) - '0';
            int len = nLength - iter - 1;
            int prefix = before[iter];
            int suffix = behind[iter];
            int total = 0;
            // 当 c 前面的部分小于 ab 时
            total += prefix * intPow10(len);
            if (x == 0) {

            } else if (x == 1) {
                total += suffix + 1;
            } else {
                total += intPow10(len);
            }
            digitOneCount += total;
        }
        return digitOneCount;
    }

    /**
     * 等价于 pow(10, index)
     * @param index
     * @return
     */
    public int intPow10 (int index) {
        if (index == 0) {
            return 1;
        } else {
            int powResult = 1;
            while (index > 0) {
                powResult *= 10;
                index--;
            }
            return powResult;
        }
    }
}
```


## Problem 25 max(好因子)

``` java
import java.util.Scanner;

/**
 * @author ysxiang
 */
public class Main{
    private final static int N = 1_000_000_007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(new Main().getGoodDivisor(n));
    }

    /**
     * solution.
     */
    public int getGoodDivisor(int n) {
        
        if (n <= 3) {
            return n;
        }
        int a = n / 3, b = n % 3;
        if (b == 1) {
            return (int) (quickPow(3, a - 1, N) * 4 % N);
        } else if (b == 2) {
            return (int) (quickPow(3, a, N) * 2 % N);
        } else {
            return (int) quickPow(3, a, N);
        }
    }
    

    /**
    * 快速求幂：
    * p^q，计算中防止溢出，对MOD求余
    */
    public long quickPow(int p, int q, int MOD) {
        long ans = 1L;
        long base = p;
        while (q != 0) {
            if (q % 2 == 1) {
                ans = ans * base % MOD;
            }
            base = base * base % MOD;
            q = q / 2;
        }
        return ans;
    }
}
```


## Problem 30 快乐数列

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.print(new Main().getResult(n));
    }

    public String getResult(int n) {
        if (n == 1) {
            return "1";
        } else if (n == 2) {
            return "11";
        }
        String str = String.valueOf(11);
        int prefix = 0, suffix = 0;
        int count = 1;
        for (int iter = 2; iter < n; iter++) {
            String tempStr = "";
            for (int index = 1; index < str.length(); index++) {
                prefix = Integer.parseInt(str.substring(index - 1, index));
                suffix = Integer.parseInt(str.substring(index, index + 1));
                if (prefix == suffix) {
                    count++;
                } else {
                    tempStr += String.valueOf(count) + String.valueOf(prefix);
                    count = 1;
                }
            }
            prefix = Integer.parseInt(str.substring(str.length() - 1, str.length()));
            tempStr += String.valueOf(count) + String.valueOf(prefix);
            str = tempStr;
            count = 1;
        }
        return str;
    }
}
```



