#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 回头看下年轻的自己
// 当年只为做题
// 做完不看 discuss, 不了解其他精彩的思路, 这也太没意思了

// 其实换一个角度这个问题很简单
// 直接按行存储就可以了
// 当然这需要空间复杂度

// 

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<vector<char>> rel(numRows, vector<char>());
        int rowCnt = 0;
        int len = s.length();

        bool down = true;
        for (int i = 0; i < len; ++i) {
            if (down) {
                rel[rowCnt++].push_back(s[i]);
            } else {
                rel[rowCnt--].push_back(s[i]);
            }
            if (numRows != 2 && (rowCnt == numRows || rowCnt == 0)) {
                down = !down;
            }
            if (rowCnt == numRows) {
                rowCnt -= 2;
            }
        }

        stringstream ss;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < rel[i].size(); ++j) {
                ss << rel[i][j];
            }
        }

        return ss.str();
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.convert("A", 2) << endl;
	return 0;
}