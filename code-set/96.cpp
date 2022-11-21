#include <cmath>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int dfs(string& str, int begin, set<string>& unique_set)
{
    if (begin == str.size()) {
        return 0;
    }
    int max_count = 0;
    for (int iter = begin; iter < str.size(); iter++) {
        string sub_str = str.substr(begin, iter - begin + 1);
        if (unique_set.find(sub_str) == unique_set.end()) { // if sub_str is not in unique_set.
            unique_set.insert(sub_str);
            max_count = max(max_count, 1 + dfs(str, iter + 1, unique_set));
            unique_set.erase(sub_str);
        }
    }
    return max_count;
}

int max_unique_split(string& str)
{
    set<string> unique_set;
    return dfs(str, 0, unique_set);
}

void solution96()
{
    string str;
    cin >> str;
    cout << max_unique_split(str) << endl;
}

int main()
{
    solution96();
    return 0;
}