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