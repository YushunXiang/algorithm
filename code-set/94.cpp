#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> get_ip_address(string& str)
{
    vector<string> result;
    int len = str.size();
    if (len < 4 || len > 12) {
        return result;
    }

    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            for (int k = 1; k < 4; k++) {
                for (int l = 1; l < 4; l++) {
                    if (i + j + k + l == len) {
                        int a = stoi(str.substr(0, i));
                        int b = stoi(str.substr(i, j));
                        int c = stoi(str.substr(i + j, k));
                        int d = stoi(str.substr(i + j + k, l));
                        if (a <= 255 && b <= 255 && c <= 255 && d <= 255) {
                            string ip = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
                            if (ip.size() == len + 3) {
                                result.push_back(ip);
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

void solution94()
{
    string str;
    cin >> str;
    vector<string> result_list = get_ip_address(str);
    for (vector<string>::iterator iter = result_list.begin(); iter < result_list.end(); iter++) {
        cout << *iter << endl;
    }
}

int main()
{
    solution94();
    return 0;
}