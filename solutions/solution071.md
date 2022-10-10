# Problem 71 羊群的合并

## Solution

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mergeSheep(priority_queue<int, vector<int>, greater<int>>& sheep_queue)
{
    int sheep1, sheep2;
    int sum = 0;
    while (sheep_queue.size() > 1) {
        sheep1 = sheep_queue.top();
        sheep_queue.pop();
        sheep2 = sheep_queue.top();
        sheep_queue.pop();
        sum += sheep1 + sheep2;
        sheep_queue.push(sheep1 + sheep2);
    }
    return sum;
}

void solution71()
{
    int sheep_queue_length;
    cin >> sheep_queue_length;
    priority_queue<int, vector<int>, greater<int>> sheep_queue; // 优先队列，从小到大
    for (int iter = 0; iter < sheep_queue_length; iter++) {
        int sheep_number;
        cin >> sheep_number;
        sheep_queue.push(sheep_number);
    }
    cout << mergeSheep(sheep_queue) << endl;
}

int main()
{
    solution71();
    return 0;
}
```