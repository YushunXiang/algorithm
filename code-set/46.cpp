#include <iostream>

using namespace std;

int nums[100];

bool canPartition(int nums_length)
{
    int sum = 0;
    for (int iter = 0; iter < nums_length; iter++) {
        sum += nums[iter];
    }
    if ((sum & 1) != 0) { // 若sum为单数
        return false;
    }
    int target = sum >> 1;
    bool* dp = new bool[target + 1];
    dp[0] = true;
    for (int iter = 0; iter < nums_length; iter++) {
        int num = nums[iter];
        if (num > target) {
            return false;
        }
        dp[num] = true;
        for (int jter = 0; jter <= target - num; jter++) {
            dp[jter + num] = dp[jter] || dp[num];
        }
    }
    return dp[target];
}

void solution46()
{
    int nums_length;
    cin >> nums_length;
    for (int iter = 0; iter < nums_length; iter++) {
        cin >> nums[iter];
    }
    cout << (canPartition(nums_length) ? "true" : "false") << endl;
}

int main()
{
    solution46();
    return 0;
}