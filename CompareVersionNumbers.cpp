#include <iostream>
#include <string>

using namespace std;

// 太考验细心程度
// 以及细节处理能力了
// 样例 0.1 vs 0.0.1
// 样例 1.1 vs 1.10
// 样例 1.2 vs 1.10

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int e1 = version1.size();
        int e2 = version2.size();

        int s1 = 0;
        int s2 = 0;
        int t1 = 0;
        int t2 = 0;

        int rel = 0;

        while (t1 < e1 && t2 < e2) {
            t1 = findCH(version1, s1, e1, '.');
            t2 = findCH(version2, s2, e2, '.');

            removeLeadingZero(version1, s1, e1);
            removeLeadingZero(version2, s2, e2);

            rel = cmpVersion(version1, s1, t1, version2, s2, t2);
            s1 = ++t1;
            s2 = ++t2;

            if (rel != 0) {
                return rel;
            }
        }

        if (t1 >= e1 && t2 < e2) {
            if (notZero(version2, t2, e2)) {
                return -1;
            }
        }
        if (t1 < e1 && t2 >= e2) {
            if (notZero(version1, t1, e1)) {
                return 1;
            }
        }

        return 0;
    }

    // compare part
    int cmpVersion(string& str1, int s1, int e1, string& str2, int s2, int e2) {
        int l1 = e1 - s1;
        int l2 = e2 - s2;

        if (l1 != l2) {
            return l1 < l2 ? -1 : 1;
        }
        else {
            while (s1 < e1 && str1[s1] == str2[s2]) {
                ++s1;
                ++s2;
            }

            if (s1 == e1) {
                return 0;
            }
            else {
                if (str1[s1] < str2[s2]) {
                    return -1;
                }
                else {
                    return 1;
                }
            }
        }
    }

    // locate dot
    int findCH(string& str, int s, int e, char ch) {
        while (s < e && str[s] != ch) {
            ++s;
        }
        return s;
    }

    int removeLeadingZero(string& str, int& s, int& e) {
        while (s < e && str[s] == '0') {
            ++s;
        }
        if (s == e) { // 0
            return s - 1;
        }
        return s;
    }

    bool notZero(string& str, int s, int e) {
        while (s < e && str[s] == '0' || str[s] == '.') {
            ++s;
        }
        return s < e;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    string s1 = "121";
    string s2 = "321";
    cout << solution.compareVersion(s1, s2) << endl;
    return 0;
}