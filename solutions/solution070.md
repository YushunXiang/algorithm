# Problem 70 拆分成对

## Solution

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int splitIntoPairs(vector<int>& nums)
{
    int min_sum = 0;
    sort(nums.begin(), nums.end());
    for (auto iter = nums.begin(); iter < nums.end(); iter++) {
        min_sum += *(iter++);
    }
    return min_sum;
}

void solution70()
{
    int nums_length;
    cin >> nums_length;
    vector<int> nums(nums_length);
    for (auto iter = nums.begin(); iter < nums.end(); iter++) {
        cin >> *(iter);
    }
    cout << splitIntoPairs(nums) << endl;
}

int main()
{
    solution70();
    return 0;
}
```