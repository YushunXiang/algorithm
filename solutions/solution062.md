# Problem 62 花样二叉树


## Solution

```cpp
#include <iostream>
#include <vector>
using namespace std;

int BST_number(int num)
{
    vector<int> kinds_number(num + 1);
    kinds_number[0] = 1;
    for (int iter = 1; iter <= num; iter++) {
        int kind_number = 0;
        for (int jter = 0; jter < iter; jter++) { // 对于有num个节点的BST，其BST的个数 == 左子树(i个节点)的个数 * 右子树(n - i - 1个节点)的个数
            kind_number += kinds_number[jter] * kinds_number[iter - jter - 1];
        }
        kinds_number[iter] = kind_number;
    }
    return kinds_number[num];
}

void solution62()
{
    int num;
    cin >> num;
    cout << BST_number(num) << endl;
}

int main()
{
    solution62();
    return 0;
}
```