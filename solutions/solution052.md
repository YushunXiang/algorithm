# Problem 52 疯狂地采矿

tag: 完全背包问题

## Solution

```cpp
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 完全背包问题
// 一个矿能采无数次
int maxValue(vector<int>& costs, vector<int>& values, int total_time)
{
    int variety_number = costs.size(); // 矿物数量
    vector<int> dp(total_time + 1);
    for (int iter = 1; iter <= variety_number; iter++) {
        for (int jter = costs[iter]; jter <= total_time; jter++) {
            dp[jter] = max(
                dp[jter - costs[iter]] + values[iter],
                dp[jter]);
        }
    }
    return dp[total_time];
}

void solution52()
{
    int total_time, variety_number;
    int cost, value;

    cin >> total_time >> variety_number;
    vector<int> costs(variety_number + 1);
    vector<int> values(variety_number + 1);
    for (int index = 1; index <= variety_number; index++) {
        cin >> cost >> value;
        costs.push_back(cost);
        values.push_back(value);
    }
    cout << maxValue(costs, values, total_time) << endl;
}

int main()
{
    solution52();
    return 0;
}
```