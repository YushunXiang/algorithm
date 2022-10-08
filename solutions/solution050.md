# Problem 50 找特定字符串

tag: 动态规划

## Sample Input

```text
abcde
ace
```

> 注意！罗扣上输入样例应该是不包含双引号的！ 
> 所有的输入也是不包含双引号的！


## Sample Output

```text
3
```

## Solution

```cpp
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int dp[101][101];

// 返回最长公共子序列的个数
// Dynamic Programming
int longest_common_subsequence(string& text1, string& text2)
{
    int text1_length = text1.length();
    int text2_length = text2.length();
    for (int iter = 1; iter <= text1_length; iter++) {
        for (int jter = 1; jter <= text2_length; jter++) {
            if (text1[iter - 1] == text2[jter - 1]) {
                dp[iter][jter] = dp[iter - 1][jter - 1] + 1;
            } else {
                dp[iter][jter] = max(
                    dp[iter][jter - 1],
                    dp[iter - 1][jter]);
            }
        }
    }
    return dp[text1_length][text2_length];
}

void solution50()
{
    string text1;
    string text2;
    cin >> text1 >> text2;
    cout << longest_common_subsequence(text1, text2) << endl;
}

int main()
{
    solution50();
    return 0;
}
```