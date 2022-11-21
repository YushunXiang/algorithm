#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 阶乘
 */
int factorial(int n)
{
    if (n == 0) {
        return 1;
    }
    int res = 1;
    for (int iter = 2; iter < n + 1; iter++) {
        res *= iter;
    }
    return res;
}

void get_permutation(int n, int k)
{
    vector<int> nums;
    vector<int> num_list;
    for (int iter = 0; iter < n; iter++) {
        num_list.push_back(iter + 1);
        int tmp = factorial(n - iter - 1);
        int index = ceil((double)k / (double)tmp) - 1;
        if (index > 0) {
            nums.push_back(index);
        } else {
            nums.push_back(0);
        }
        k %= tmp;
        if (k == 0) {
            k = tmp;
        }
    }
    for (int iter : nums) {
        cout << num_list[iter];
        num_list.erase(num_list.begin() + iter);
    }
    cout << endl;
}

void solution26()
{
    int n;
    int k;
    cin >> n >> k;
    get_permutation(n, k);
}

int main()
{
    solution26();
    return 0;
}