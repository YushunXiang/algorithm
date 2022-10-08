#include <iostream>

using namespace std;

int nums[200];
int dp[201];

// Dynamic Programming
int combination_sum(int nums_length, int target)
{
    dp[0] = 1;
    for (int iter = 1; iter <= target; iter++) {
        for (int index = 0; index < nums_length; index++) {
            int num = nums[index];
            if (iter >= num) {
                dp[iter] += dp[iter - num];
            }
        }
    }
    return dp[target];
}

void solution43()
{
    int num, target;
    cin >> num;
    for (int iter = 0; iter < num; iter++) {
        cin >> nums[iter];
    }
    cin >> target;
    cout << combination_sum(num, target) << endl;
}

int main()
{
    solution43();
    return 0;
}