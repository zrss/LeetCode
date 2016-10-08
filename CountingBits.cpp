#include <iostream>
#include <vector>

using namespace std;

// 方法1
// 时间复杂度O(n * number of 1)

// 求二进制中1的个数
// while (x) {
//     x &= (x - 1);
// }

// 方法2
// 找规律
// 0 - 15
// 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4
// [1, 2, 2, 3] -> [2, 3, 3, 4]
// [1, 2] -> [2, 3]
// [0, 1] -> [1, 2]
// [0] -> [1]

// 不难发现一个空间复杂度O(n)，时间复杂度O(n)的方法
// [0] -> [1]
// [0, 1] -> [1, 2]
// [0, 1, 1, 2] -> [1, 2, 2, 3]
// [0, 1, 1, 2, 1, 2, 2, 3] -> [1, 2, 2, 3, 2, 3, 3, 4]

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int cnt = num + 1;
        int pos = 1;
        while (pos < cnt) {
            int len = pos;
            for (int i = 0; pos < cnt && i < len; ++i) {
                result[pos++] = result[i] + 1;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    auto rel = solution.countBits(8);
    
    for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}