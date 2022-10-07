# Problem 27 最小非零乘积

## Solution

```java
import java.util.Scanner;

/**
 * OJ
 *
 * @author ysxiang
 */
public class Main {
    public final static long MOD = 1_000_000_007;

    public int minNonZeroProduct(int index) {
        long a = (1L << index) - 1L;
        long b = a - 1L;
        long c = b / 2L;
        return (int) ((a % MOD) * (quickPow(b % MOD, c)) % MOD);
    }

    /**
     * 快速幂
     *
     * @param a
     * @param index
     * @return
     */
    public long quickPow(long a, long index) {
        long base = a;
        long ans = 1L;
        while (index > 0) {
            if ((index & 1L) == 1L) {
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            index >>= 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int p = scanner.nextInt();
        System.out.println(new Main().minNonZeroProduct(p));
    }
}

```