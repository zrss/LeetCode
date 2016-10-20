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

// 解法2
// discuss 中说的滑动窗口，窗口开始位置为s，当前遍历位置为c
// 思路比较清奇
// 首先也是因为只需要考虑 26 个字母
// 计算[s, c]间的字符总和 Sum, 以及出现次数最大的字符数 Max
// 因此需要 Sum - Max 次可以调整[s, c]为全部重复的字符
// 当 Sum - Max > k 时，移动窗口开始位置到下一个 s = s + 1

class Solution {
public:
    int characterReplacement1(string s, int k) {
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

    int characterReplacement(string s, int k) {
        int len = s.length();
        int maxLen = 0;

        int chCnt[26];
        memset(chCnt, 0, sizeof(chCnt));

        for (int start = 0, cur = 0; start < len; ++start) {
            while (cur < len) { // 窗口右侧
                ++chCnt[s[cur] - 'A'];
                if (count(chCnt) > k) {
                    --chCnt[s[cur] - 'A'];
                    break;
                }
                ++cur;
            }
            maxLen = max(maxLen, cur - start);
            --chCnt[s[start] - 'A']; // 窗口左侧
        }

        return maxLen;   
    }

    int count(int chCnt[]) {
        int maxCnt = chCnt[0];
        int sumCnt = chCnt[0];
        for (int i = 1; i < 26; ++i) {
            maxCnt = max(maxCnt, chCnt[i]);
            sumCnt += chCnt[i];
        }
        return sumCnt - maxCnt;
    }
};

int main(int argc, char const *argv[]) {
    cout << Solution().characterReplacement("AAABBBCCCC", 2) << endl;
    return 0;
}