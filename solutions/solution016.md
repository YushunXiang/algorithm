# Problem 16 "有效子数组"个数

感觉我这个方法算法太傻了，得用cpp才能过

```cpp
/**
 * 因为有些题用java写会RE，但用cpp就没问题
 * @author ysxiang
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int effectiveSub(std::vector<int> &nums);

void task16()
{
    string str;

    getline(cin, str);

    vector<int> chars;
    for (int i = 0; i < str.length(); i += 2)
    {
        if (str.at(i) != 'q')
        {
            chars.push_back(str.at(i) - '0');
        }
    }

    std::cout << effectiveSub(chars) << std::endl;

    return;
}

int effectiveSub(std::vector<int> &nums)
{
    int nums_length = nums.size();
    int sub_count = 0;
    for (int i = 0; i <= nums_length; i++)
    {
        for (int j = i; j <= nums_length; j++)
        {
            int zero_count = 0;
            int one_count = 0;
            for (int k = i; k < j; k++)
            {
                if (nums[k])
                {
                    one_count++;
                }
                else
                {
                    zero_count++;
                }
            }

            if (one_count > zero_count)
            {
                sub_count++;
            }
        }
    }
    return sub_count;
}

int main()
{
    task16();
}
```

后来听说这个方法也会超时，估计是数据量变大了，不能用暴力法偷懒了QAQ
所以又搞了一个时间复杂度为 O(nlogn) 的算法

```cpp
/**
 * @author ysxiang
 */
#include <iostream>
#include <vector>

using namespace std;

int effectiveSub(std::vector<int>& nums);
void solution16();
int lowbit(int x);
void add(int x, int v, int n);
int query(int x);

static constexpr int MOD = 1000000007;
static vector<int> tree(200010);

void solution16()
{
    int temp;
    vector<int> chars;
    while (cin >> temp) {
        chars.push_back(temp);
    }
    std::cout << effectiveSub(chars) << std::endl;
    return;
}

int lowbit(int x)
{
    return x & -x;
}

int query(int x)
{
    int ans = 0;
    for (int iter = x; iter > 0; iter -= lowbit(iter)) {
        ans += tree[iter];
    }
    return ans;
}

void add(int x, int v, int n)
{
    for (int iter = x; iter <= 2 * n + 1; iter += lowbit(iter)) {
        tree[iter] += v;
    }
}

int effectiveSub(std::vector<int>& nums)
{
    int nums_length = nums.size();
    vector<int> sum(nums_length + 1);
    int sub_count = 0;
    for (int iter = 1; iter <= nums_length; iter++) {
        sum[iter] = sum[iter - 1] + ((nums[iter - 1] == 0) ? -1 : 1); // 将nums数组的[0, 1]映射到[-1, 1],并累加
    }
    for (int iter = 0; iter <= nums_length; iter++) {
        int temp = sum[iter] + nums_length + 1; // [-n, n] -> [1, 2n + 1]
        sub_count = (sub_count + query(temp - 1)) % MOD;
        add(temp, 1, nums_length);
    }

    return sub_count;
}

int main()
{
    solution16();
}
```