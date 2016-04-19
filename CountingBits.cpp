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
        vector<int> rel;
        if (num < 0) {
            return rel;
        }

        rel.resize(num + 1);
        int len = 1;
        
        int next = 1;
        int start = 0;

        while (next <= num) {
            while (next <= num && start < len) {
                rel[next++] = rel[start++] + 1;
            }
            len <<= 1;
            start ^= start;
        }

        return rel;
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