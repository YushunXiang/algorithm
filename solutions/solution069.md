# Problem 69 摇摆序列

## Solution

```cpp
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int maxSwingLength(vector<int>& nums)
{
    int nums_length = nums.size();
    int up = 1, down = 1;
    for (int iter = 1; iter < nums_length; iter++) {
        if (nums[iter] > nums[iter - 1]) {
            up = down + 1;
        }
        if (nums[iter] < nums[iter - 1]) {
            down = up + 1;
        }
    }
    return max(up, down);
}

void solution69()
{
    int nums_length;
    cin >> nums_length;
    vector<int> nums(nums_length);
    for (auto iter = nums.begin(); iter < nums.end(); iter++) {
        cin >> *(iter);
    }
    cout << maxSwingLength(nums) << endl;
}

int main()
{
    solution69();
    return 0;
}
```