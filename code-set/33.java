import java.math.BigInteger;
import java.util.Scanner;


/**
 * @author ysxiang
 */

class Main {
    public final int MOD = 1337;

    /**
     * calculate (a ^ b) mod MOD
     * @param a
     * @param b
     * @return
     */
    public long bigPow(int a, String b) {
        long ans = 1L;
        long base = a;
        BigInteger big = new BigInteger(String.valueOf(b));
        while (!big.equals(new BigInteger(String.valueOf(0)))) {
            if (big.mod(new BigInteger(String.valueOf(2))).equals(new BigInteger(String.valueOf(1)))) {
                ans = ans * base % MOD;
            }
            base = base * base % MOD;
            big = big.divide(new BigInteger(String.valueOf(2)));
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int n = sc.nextInt();
        StringBuffer b = new StringBuffer();
        for (int i = 0; i < n; i++) {
            b.append(sc.next());
        }
        System.out.println(new Main().bigPow(a, b.toString()));
    }
}