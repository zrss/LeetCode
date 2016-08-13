#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rel;
        vector<string> tmp;

        // 超过长度为 12 的不是合法的IP
        if (s.length() <= 12) {
            locate(s, 0, 0, rel, tmp);
        }

        return rel;
    }

    void locate(string& s, int cur, int seg, vector<string>& rel, vector<string>& tmp) {
        if (seg == 4 && cur == s.length()) {
            string ip = tmp[0];
            for (int i = 1; i < 4; ++i) {
                ip += "." + tmp[i];
            }
            rel.push_back(ip);
            return;
        }

        for (int l = 1; l <= 3; ++l) {
            if (cur + l <= s.length() && validIPSeg(s, cur, cur + l)) {
                tmp.push_back(s.substr(cur, l));
                locate(s, cur + l, seg + 1, rel, tmp);
                tmp.pop_back();
            }
            else {
                break;
            }
        }
    }

    bool validIPSeg(string& s, int start, int end) {
        if (end - start > 1 && s[start] == '0') { // 开头不能为 0
            return false;
        }
        if (end - start == 3) { // 不能超过 255
            return strcmp(s.substr(start, end - start).c_str(), "255") <= 0;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    vector<string> rel = solution.restoreIpAddresses("010010");
    for (auto each : rel) {
        cout << each << endl;
    }
    return 0;
}