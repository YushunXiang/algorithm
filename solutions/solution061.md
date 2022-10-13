# Problem 61 最大增序长度

## Solution

```cpp
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int maxIncreaseLength(vector<int>& nums)
{
    int nums_length = nums.size();
    int max_increase_length = 0;
    vector<int> dp(nums_length);
    for (int iter = 0; iter < nums_length; iter++) {
        for (int jter = 0; jter < iter; jter++) {
            if (nums[jter] < nums[iter]) {
                dp[iter] = max(dp[jter] + 1, dp[iter]);
            }
        }
        max_increase_length = max(dp[iter], max_increase_length);
    }
    return max_increase_length + 1;
}

void solution61()
{
    int nums_length;
    cin >> nums_length;
    vector<int> nums(nums_length);
    for (auto iter = nums.begin(); iter < nums.end(); iter++) {
        cin >> *(iter);
    }
    cout << maxIncreaseLength(nums) << endl;
}

int main()
{
    solution61();
    return 0;
}
```