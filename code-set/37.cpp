#include <cmath>
#include <iostream>

using namespace std;

int cost[50][50];
int dp[50][50];

int min_cost(int m)
{
    for (int iter = 0; iter < m; iter++) {
        for (int jter = 0; jter < m; jter++) {
            if (iter == 0 && jter == 0) {
                dp[0][0] = cost[0][0];
            } else if (iter == 0 && jter > 0) {
                dp[0][jter] = dp[0][jter - 1] + cost[0][jter];
            } else if (iter > 0 && jter == 0) {
                dp[iter][0] = dp[iter - 1][0] + cost[iter][0];
            } else {
                dp[iter][jter] = min(
                    dp[iter - 1][jter] + cost[iter][jter],
                    dp[iter][jter - 1] + cost[iter][jter]);
            }
        }
    }
    return dp[m - 1][m - 1];
}

void solution37()
{
    int m;
    cin >> m;
    for (int iter = 0; iter < m; iter++) {
        for (int jter = 0; jter < m; jter++) {
            cin >> cost[iter][jter];
        }
    }
    cout << min_cost(m) << endl;
}

int main()
{
    solution37();
    return 0;
}