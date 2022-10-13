#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int x_direction[4] = { 0, 0, -1, 1 };
int y_direction[4] = { 1, -1, 0, 0 };

// 是否在题目区域内，若在，则返回true
bool inArea(int x, int y, int row_length, int col_length)
{
    if ((x >= 0 && y >= 0) && (x < row_length && y < col_length)) {
        return true;
    } else {
        return false;
    }
}

int maxDistance(vector<vector<int>>& matrix, vector<vector<int>>& max_distance, int x, int y)
{
    int row_length = matrix.size();
    int col_length = matrix[0].size();
    if (max_distance[x][y] > 0) {
        return max_distance[x][y];
    }
    max_distance[x][y] = 1;
    for (int iter = 0; iter < 4; iter++) {
        int to_x = x + x_direction[iter];
        int to_y = y + y_direction[iter];
        if (inArea(to_x, to_y, row_length, col_length) && matrix[x][y] > matrix[to_x][to_y]) {
            max_distance[x][y] = max(
                maxDistance(matrix, max_distance, to_x, to_y) + 1,
                max_distance[x][y]);
        }
    }
    return max_distance[x][y];
}

void solution53()
{
    int row, col;
    int max_dis = 0;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    vector<vector<int>> max_distance(row, vector<int>(col)); // 判断是否经历过这个点
    for (int iter = 0; iter < row; iter++) {
        for (int jter = 0; jter < col; jter++) {
            cin >> matrix[iter][jter];
        }
    }

    for (int iter = 0; iter < row; iter++) {
        for (int jter = 0; jter < col; jter++) {
            max_dis = max(
                maxDistance(matrix, max_distance, iter, jter),
                max_dis);
        }
    }
    cout << max_dis << endl;
}

int main()
{
    solution53();
    return 0;
}