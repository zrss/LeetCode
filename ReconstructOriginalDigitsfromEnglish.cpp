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

// discuss 中发现一个 genius 的思路, 避免了排序, 基本思想是一样的, 不过人家直接统计的数字个数
// 见 originalDigits1

// seven -> count[7] - count[6]
// five -> count[5] - count[4]
// three -> count[3] - count[2] - count[8]
// one -> count[1] - count[0] - count[2] - count[4]
// nine -> (count[9] - count[7] - count[1]) / 2
// 注意 9 有两个 n

class Solution {
public:
    // 63 ms
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

    // 49 ms
    string originalDigits1(string s) {
        int count[10];
        memset(count, 0, sizeof(count));

        char target[] = "zwgxusfton";
        int nums[] = {0, 2, 8, 6, 4, 7, 5, 3, 1, 9};

        int len = s.length();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (s[i] == target[j]) {
                    ++count[nums[j]];
                    break;
                }
            }
        }

        count[7] -= count[6];
        count[5] -= count[4];
        count[3] -= (count[2] + count[8]);
        count[1] -= (count[0] + count[2] + count[4]);
        count[9] -= (count[7] + count[1]);
        count[9] >>= 1;

        stringstream ss;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                ss << i;
            }
        }

        return ss.str();
    }
};