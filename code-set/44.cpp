#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max_profit(vector<int>& prices)
{
    int prices_length = prices.size();
    vector<int> profits(prices_length);
    for (int i = 1; i < prices_length; i++) {
        profits[i] = prices[i] - prices[i - 1];
    }
    vector<vector<int>> dp(prices_length + 1, vector<int>(2));
    for (int i = 1; i < prices_length; i++) {
        dp[i][0] = max(profits[i], dp[i - 1][0] + profits[i]);
    }
    for (int i = 1; i < prices_length; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i][0]);
    }
    for (int i = prices_length - 1; i >= 0; i--) {
        dp[i][1] = max(profits[i], dp[i + 1][1] + profits[i]);
    }
    for (int i = prices_length - 1; i >= 0; i--) {
        dp[i][1] = max(dp[i][1], dp[i + 1][1]);
    }
    int result = 0;
    for (int i = 0; i < prices_length; i++) {
        result = max(result, dp[i][0] + dp[i + 1][1]);
    }
    return result;
}

void solution44()
{
    int nums_length;
    cin >> nums_length;
    vector<int> nums(nums_length);
    for (auto iter = nums.begin(); iter < nums.end(); iter++) {
        cin >> *iter;
    }
    cout << max_profit(nums) << endl;
}

int main()
{
    solution44();
    return 0;
}