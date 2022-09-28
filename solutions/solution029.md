# Problem 29 全排列！

## Solution

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

void task29()
{
    int num;
    std::cin >> num;
    int *nums = new int[11];
    for (int iter = 0; iter < num; iter++)
    {
        nums[iter] = iter + 1;
    }
    do {
        for (int iter = 0; iter < num; iter++)
        {
            std::cout << nums[iter];
        }
        std::cout << std::endl;
    } while (std::next_permutation(nums, nums + num));
    return;
}


int main()
{
    task29();
    return 0;
}
```