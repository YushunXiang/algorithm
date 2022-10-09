# Problem 72 买到所有玩具



## Solution

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<int>& toy_prices)
{
    int toy_prices_length = toy_prices.size();
    int total_price = 0;
    sort(toy_prices.begin(), toy_prices.end());
    for (int iter = toy_prices_length - 1; iter >= 1; iter -= 3) {
        total_price += toy_prices[iter] + toy_prices[iter - 1];
    }
    if (toy_prices_length % 3 == 1) {
        total_price += toy_prices[0];
    }
    return total_price;
}

void solution72()
{
    int toy_number;
    cin >> toy_number;
    vector<int> toy_prices(toy_number);
    for (vector<int>::iterator it = toy_prices.begin(); it < toy_prices.end(); it++) {
        cin >> *it;
    }
    cout << minCost(toy_prices) << endl;
}

int main()
{
    solution72();
    return 0;
}
```