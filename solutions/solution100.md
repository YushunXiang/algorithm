# Problem 100 凑数的题

## Solution

```cpp
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

static constexpr int TARGET = 24;
static constexpr double EPSILON = 1e-6;
static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

bool solve(vector<double>& nums)
{
    if (nums.size() == 0) {
        return false;
    }
    if (nums.size() == 1) {
        return fabs(nums[0] - TARGET) < EPSILON;
    }
    int nums_length = nums.size();
    for (int iter = 0; iter < nums_length; iter++) {
        for (int jter = 0; jter < nums_length; jter++) {
            if (iter != jter) {
                vector<double> list2;
                for (int kter = 0; kter < nums_length; kter++) {
                    if (kter != iter && kter != jter) {
                        list2.emplace_back(nums[kter]);
                    }
                }
                for (int kter = 0; kter < 4; kter++) {
                    if (kter < 2 && iter > jter) {
                        continue;
                    }
                    switch (kter) {
                    case ADD:
                        list2.emplace_back(nums[iter] + nums[jter]);
                        break;
                    case MULTIPLY:
                        list2.emplace_back(nums[iter] * nums[jter]);
                        break;
                    case SUBTRACT:
                        list2.emplace_back(nums[iter] - nums[jter]);
                        break;
                    case DIVIDE:
                        if (fabs(nums[jter]) < EPSILON) {
                            continue;
                        }
                        list2.emplace_back(nums[iter] / nums[jter]);
                        break;
                    default:
                        break;
                    }
                    if (solve(list2)) {
                        return true;
                    }
                    list2.pop_back();
                }
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int>& nums)
{
    vector<double> double_nums;
    for (const int& num : nums) {
        double_nums.emplace_back(static_cast<double>(num));
    }
    return solve(double_nums);
}

void solution100()
{
    vector<int> nums(4);
    for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++) {
        cin >> *(iter);
    }
    cout << (judgePoint24(nums) ? "true" : "false") << endl;
}

int main()
{
    solution100();
    return 0;
}
```