// 一开始想简单了
// 统计字符出现次数
// 从 zero 到 nine 统计 完事, 后来发现这样并不对

// 索性分析一下数字字符串的规律 发现
// z -> zero
// w -> two
// g -> eight
// x -> six
// u -> four

// 以上为唯一确定

// 以下按顺序排除, 可唯一确定

// s -> seven
// f -> five
// t -> three
// o -> one
// n -> nine

class Solution {
public:
    string originalDigits(string s) {
        int chCnt[26];
        memset(chCnt, 0, sizeof(chCnt));

        int len = s.length();
        for (int i = 0; i < len; ++i) {
            ++chCnt[s[i] - 'a'];
        }

        stringstream ss;
        char seq[] = "zwgxusfton";
        string numsStr[] = {"zero", "two", "eight", "six", "four", "seven", "five", "three", "one", "nine"};
        int nums[] = {0, 2, 8, 6, 4, 7, 5, 3, 1, 9};

        for (int i = 0; i < 10; ++i) {
            while (chCnt[seq[i] - 'a'] > 0) {
                ss << nums[i];
                int tlen = numsStr[i].length();
                for (int j = 0; j < tlen; ++j) {
                    --chCnt[numsStr[i][j] - 'a'];
                }
            }
        }

        string rel = ss.str();
        sort(rel.begin(), rel.end());

        return rel;
    }
};