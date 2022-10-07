# Problem 32 特殊数字

TLE了

时间复杂度$O(n)$

```cpp
#include <iostream>
#include <cstring>

typedef long long ll;
using namespace std;
int figures[15];

// 特殊数字
ll special_figure_count(ll low, ll high)
{
    ll count = 0;
    for (ll iter = low; iter < high; iter++) {
        ll x = iter;
        int index = 0;
        memset(figures, 0, sizeof(figures));
        while (x > 0) {
            int ones_unit = (int)(x % 10L); // 个位数
            x /= 10L;
            figures[index++] = ones_unit;
        }
        if ((index & 1) == 1) { // 为长度为基数
            int temp = figures[index >> 1];
            if ((temp != 0 || temp != 1) || temp != 8) {
                continue;
            }
        }
        bool flag = true;
        for (int jter = 0; jter < ((index + 1) >> 1); jter++) {
            if (figures[jter] == 0 && figures[index - jter - 1] == 0) {
                continue;
            }
            if (figures[jter] == 1 && figures[index - jter - 1] == 1) {
                continue;
            }
            if (figures[jter] == 8 && figures[index - jter - 1] == 8) {
                continue;
            }
            if (figures[jter] == 9 && figures[index - jter - 1] == 6) {
                continue;
            }
            if (figures[jter] == 6 && figures[index - jter - 1] == 9) {
                continue;
            }
            flag = false;
            break;
        }
        if (!flag) {
            continue;
        }
        count++;
    }

    return count;
}

void solution32()
{
    ll low;
    ll high;
    cin >> low >> high;
    cout << special_figure_count(low, high) << endl;
}


int main()
{
    solution32();
    return 0;
}
```

