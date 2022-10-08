#include <iostream>
#include <cmath>

using namespace std;

int nums[200];

int maxProduct(int nums_length)
{
    int max_product = 1;
    int min_product = 1;
    int max_value = 0;
    for (int iter = 0; iter < nums_length; iter++) {
        if (nums[iter] < 0) {
            int temp = max_product;
            max_product = min_product;
            min_product = temp;
        }
        max_product = max(max_product * nums[iter], nums[iter]);
        min_product = min(min_product * nums[iter], nums[iter]);
        max_value = max(max_product, max_value);
    }
    return max_value;
}

void solution48()
{
    int nums_length;
    cin >> nums_length;
    for (int iter = 0; iter < nums_length; iter++) {
        cin >> nums[iter];
    }
    cout << maxProduct(nums_length) << endl;
}

int main()
{
    solution48();
}