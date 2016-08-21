#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// 分治
// 遍历所有情况

// 需要反复理解

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> num;
        vector<int> op;

        int digits = 0;
        bool remain = false;
        for (int i = 0; i < input.length(); ++i) {
            if (isdigit(input[i])) {
                remain = true;
                digits *= 10;
                digits += (input[i] - '0');
            } else {
                remain = false;
                num.push_back(digits);
                digits ^= digits;

                op.push_back(input[i]);
            }
        }

        if (remain) {
            num.push_back(digits);
        }

        return divide_conquer(num, op, 0, num.size());
    }

    // [begin, end)
    vector<int> divide_conquer(vector<int>& num, vector<int>& op, int begin, int end) {
        if (begin + 1 == end) {
            return vector<int>{num[begin]};
        }
        vector<int> result;
        for (int nextEnd = begin + 1; nextEnd < end; ++nextEnd) {
            vector<int> left = divide_conquer(num, op, begin, nextEnd);
            vector<int> right = divide_conquer(num, op, nextEnd, end);
            for (int l : left) {
                for (int r : right) {
                    result.push_back(op[nextEnd - 1] == '+'? l + r: op[nextEnd - 1] == '-'? l - r : l * r);
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    string input = "2-1-1";
    vector<int> rel = solution.diffWaysToCompute(input);
    for (int each : rel) {
        cout << each << " ";
    }
    cout << endl;
    return 0;
}