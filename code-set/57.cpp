#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(string& sentence, vector<string>& words)
{
    int sentence_length = sentence.size();
    bool* dp = new bool[sentence_length + 1]();
    dp[0] = true;
    for (int i = 0; i < sentence_length; i++) {
        if (dp[i]) {
            for (int j = i; j < sentence_length; j++) {
                if (find(words.begin(), words.end(), sentence.substr(i, j - i + 1)) != words.end()) {
                    dp[j + 1] = true;
                }
            }
        }
    }
    return dp[sentence_length];
}

void solution57()
{
    int words_number;
    string sentence;
    cin >> sentence >> words_number;
    vector<string> words(words_number);
    for (vector<string>::iterator iter = words.begin(); iter < words.end(); iter++) {
        cin >> *iter;
    }
    cout << (solve(sentence, words) ? "True" : "False") << endl;
}

int main()
{
    solution57();
    return 0;
}