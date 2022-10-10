#include <iostream>

using namespace std;

bool isNAPowerOfK(int n, int k);

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    cout << isNAPowerOfK(n, k) << endl;
    return 0;
}

bool isNAPowerOfK(int n, int k)
{
    if (n < k) {
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    } else if (n == k) {
        return true;
    } else if (k == 1) {
        return false;
    } else {
        int product = k;
        while (product < n) {
            product *= product;
        }
        if (product == n) {
            return true;
        } else {
            while (product > n) {
                product /= k;
            }
            if (product == n) {
                return true;
            }
        }
        return false;
    }
}