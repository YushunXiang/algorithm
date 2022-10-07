/**
 * 因为有些题用java写会RE，但用cpp就没问题
 * @author ysxiang
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int effectiveSub(std::vector<int> &nums);

void task16()
{
    string str;

    getline(cin, str);

    vector<int> chars;
    for (int i = 0; i < str.length(); i += 2)
    {
        if (str.at(i) != 'q')
        {
            chars.push_back(str.at(i) - '0');
        }
    }

    std::cout << effectiveSub(chars) << std::endl;

    return;
}

int effectiveSub(std::vector<int> &nums)
{
    int nums_length = nums.size();
    int sub_count = 0;
    for (int i = 0; i <= nums_length; i++)
    {
        for (int j = i; j <= nums_length; j++)
        {
            int zero_count = 0;
            int one_count = 0;
            for (int k = i; k < j; k++)
            {
                if (nums[k])
                {
                    one_count++;
                }
                else
                {
                    zero_count++;
                }
            }

            if (one_count > zero_count)
            {
                sub_count++;
            }
        }
    }
    return sub_count;
}

int main()
{
    task16();
}