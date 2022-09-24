# Algorithm

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