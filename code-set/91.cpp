#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> result;
void dfs(int n, int i, vector<int>& path);

void get_factors(int n)
{
    if (n <= 3) {
        return;
    }
    vector<int> path;
    dfs(n, 2, path);
}

void dfs(int n, int i, vector<int>& path)
{
    if (n == 1) {
        if (path.size() > 1) {
            result.push_back(vector<int>(path));
        }
        return;
    }
    for (int j = i; j <= n; j++) {
        if (n % j == 0) {
            path.push_back(j);
            dfs(n / j, j, path);
            path.erase(path.end() - 1);
        }
    }
}

void solution91()
{
    int num;
    cin >> num;
    get_factors(num);
    for (vector<vector<int>>::iterator iter = result.begin(); iter < result.end(); iter++) {
        vector<int> each_result = *iter;
        cout << "[";
        for (vector<int>::iterator jter = each_result.begin(); jter < each_result.end() - 1; jter++) {
            cout << *jter << ", ";
        }
        cout << *(each_result.end() - 1) << "]" << endl;
    }
}

int main()
{
    solution91();
    return 0;
}