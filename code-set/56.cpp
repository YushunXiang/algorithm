#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int order_number_pair(vector<int>& arr)
{
    if (arr.size() < 3) {
        return 0;
    }
    int count = 0;
    for (vector<int>::iterator iter = arr.begin(); iter < arr.end(); iter++) {
        for (vector<int>::iterator jter = iter + 1; jter < arr.end(); jter++) {
            for (vector<int>::iterator kter = jter + 1; kter < arr.end(); kter++) {
                int difference1 = *jter - *iter;
                int difference2 = *kter - *jter;
                if ((difference1 > 0 && difference2 > 0) || (difference1 < 0 && difference2 < 0)) {
                    count++;
                }
            }
        }
    }
    return count;
}

void solution56()
{
    int n;

    cin >> n;
    vector<int> array(n);
    for (vector<int>::iterator iter = array.begin(); iter < array.end(); iter++) {
        cin >> *iter;
    }

    cout << order_number_pair(array) << endl;
}

int main()
{
    solution56();
    return 0;
}