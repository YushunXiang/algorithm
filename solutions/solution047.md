# Problem 47 宝石交易

## Solution

```cpp
#include <algorithm>
#include <iostream>

using namespace std;

int coins[12];

int coinChange(int coins_length, int amount)
{
    for (int iter = coins_length - 1; iter >= 0; iter--) {
        int coin = coins[iter];
        if (coin > amount) {
            continue;
        } else if (coin == amount) {
            return 1;
        } else {
            return coinChange(coins_length, amount - coin) + 1;
        }
    }
    cout << -1 << endl;
    exit(0);
}

void solution47()
{
    int coins_length, amount; // 宝石个数，总价格
    cin >> coins_length;
    for (int index = 0; index < coins_length; index++) {
        cin >> coins[index];
    }
    cin >> amount;
    sort(coins, coins + coins_length);
    cout << coinChange(coins_length, amount) << endl;
}

int main()
{
    solution47();
    return 0;
}
```