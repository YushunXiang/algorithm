#include <iostream>
#include <vector>
using namespace std;

int BST_number(int num)
{
    vector<int> kinds_number(num + 1);
    kinds_number[0] = 1;
    for (int iter = 1; iter <= num; iter++) {
        int kind_number = 0;
        for (int jter = 0; jter < iter; jter++) {
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