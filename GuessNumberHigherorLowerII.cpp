#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;


// 动态规划
// d[i ... j]，区间 i - j 的最优选择，即持有钱数
// d[i ... j] = min{x + max(d[i, x - 1], d[x + 1, j])}

// i >= j d[i][j] = 0

// 按区间长度，自底向上计算即可

#define MAX_LEN 1024

class Solution {
public:
    int getMoneyAmount(int n) {
        int d[MAX_LEN][MAX_LEN];
        memset(d, 0, sizeof(d));

        for (int l = 1; l <= n; ++l) { // 区间长度
            for (int s = 1; s <= n - l + 1; ++s) { // 区间开始
                int e = s + l - 1; // 区间结束
                if (s != e) { // 区间长度不为1
                    int rel = INT_MAX;
                    for (int x = s; x <= e; ++x) {
                        rel = min(rel, x + max(d[s][x - 1], d[x + 1][e]));
                    }
                    d[s][e] = rel;
                }
            }
        }

        return d[1][n];
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.getMoneyAmount(6) << endl;
    return 0;
}