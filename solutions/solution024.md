# Problem 24 是二叉搜索树吗？

tag: 递归

## solution

```cpp
#include <cstdio>
#include <iostream>

using namespace std;
// 二叉搜索树
int index = 0;
int arr[2000];
bool is_end = false;

bool judgeBST(int start, int end)
{
    if (start >= end) {
        return true;
    }
    int middle = end;
    for (int iter = start; iter < end; iter++) {
        if (arr[iter] > arr[end]) {
            middle = iter;
            break;
        }
    }
    if (middle == end) {
        return judgeBST(start, end - 1);
    }
    for (int iter = middle; iter < end; iter++) {
        if (arr[iter] < arr[end]) {
            return false;
        }
    }
    if (start == middle) {
        return judgeBST(middle, end - 1);
    }
    return judgeBST(start, middle - 1) && judgeBST(middle, end - 1);
}

int read()
{
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    int number = 0;
    while (ch >= '0' && ch <= '9') {
        number = number * 10 + ch - '0';
        ch = getchar();
    }
    if (ch == ']') {
        is_end = true;
    }
    return number;
}

void solution24()
{
    while (!is_end) {
        arr[index++] = read();
    }
    if (judgeBST(0, index - 1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

int main()
{
    solution24();
    return 0;
}
```