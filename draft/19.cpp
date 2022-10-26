#include <iostream>
#include <vector>
using namespace std;

int list[20001];

vector<int> rightBigger(vector<int>& nums)
{
    int nums_length = nums.size();
    vector<int> res(nums_length, 0); // 保存结果

    for (int iter = nums_length - 1; iter >= 0; iter--) {
        list[nums[iter] + 10000] += 1;
        for (int jter = 0; jter < nums[iter] + 10000; jter++) {
            res[iter] += list[jter];
        }
    }
    return res;
}

void solution19()
{
    vector<int> nums;
    int temp = 0;
    while (cin >> temp) //以任何字母为结束，输入中用q控制结束
    {
        nums.push_back(temp); //填充数据
    }
    vector<int> countR = rightBigger(nums);
    for (int i = 0; i < countR.size() - 1; i++) {
        cout << countR[i] << " ";
    }
    cout << countR[countR.size() - 1] << endl;
}

int main()
{
    solution19();
}