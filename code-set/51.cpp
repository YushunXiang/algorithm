#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 背包问题
// 一个矿只能采一次
int maxValue(vector<int>& costs, vector<int>& values, int total_time)
{
    int variety_number = costs.size(); // 矿物数量
    vector<vector<int>> dp(variety_number + 1, vector<int>(total_time + 1));
    for (int iter = 1; iter <= variety_number; iter++) {
        for (int jter = 1; jter <= total_time; jter++) {
            if (jter >= costs[iter]) { // 替换出背包里的物品
                dp[iter][jter] = max(
                    dp[iter - 1][jter - costs[iter]] + values[iter],
                    dp[iter - 1][jter]);
            } else { // 按照背包原来的物品
                dp[iter][jter] = dp[iter - 1][jter];
            }
        }
    }
    return dp[variety_number][total_time];
}

void solution51()
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
    solution51();
    return 0;
}