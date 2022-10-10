# Problem 11 n = k^x ? （n是k的幂吗）


## Java Solution

```java
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
```

## Cpp Solution

```cpp
#include <iostream>

using namespace std;

bool isNAPowerOfK(int n, int k);

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    cout << isNAPowerOfK(n, k) << endl;
    return 0;
}

bool isNAPowerOfK(int n, int k)
{
    if (n < k) {
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    } else if (n == k) {
        return true;
    } else if (k == 1) {
        return false;
    } else {
        int product = k;
        while (product < n) {
            product *= product;
        }
        if (product == n) {
            return true;
        } else {
            while (product > n) {
                product /= k;
            }
            if (product == n) {
                return true;
            }
        }
        return false;
    }
}
```