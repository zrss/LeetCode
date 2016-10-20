#include <string>
#include <iostream>
#include <queue>

using namespace std;

// 想了好久
// 题意大概是
// 可以至多替换字符串中的k个字符
// 求最长的连续的重复的字符串长度

// 实际上重复的字符串的字符只有 26 个
// 所有循环外层为 26 个字符
// 内层循环 直接扫描
// 使用一个队列记录遇到的不同字符的位置
// 当使用完k个字符后，修改start位置为队头位置的下一个

// 需要注意 k == 0 的情况
// 即队列长度为 0

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int maxLen = 0;

        for (int i = 0; i < 26; ++i) {
            char t = 'A' + i;

            queue<int> q;
            int c = 0;
            int start = 0;
            int tk = k;
            while (c < len) {
                if (s[c] != t) {
                    if (tk > 0) {
                        --tk;
                    } else {
                        if (!q.empty()) {
                            start = q.front() + 1;
                            q.pop();
                        }
                    }
                    if (k != 0)
                        q.push(c);
                    else
                        start = c + 1; // ps
                }
                maxLen = max(maxLen, c - start + 1);
                ++c;
            }
        }

        return maxLen;   
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().characterReplacement("AAABBBCCCC", 2) << endl;
    return 0;
}