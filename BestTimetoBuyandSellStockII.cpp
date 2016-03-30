#include <iostream>
#include <vector>

using namespace std;

// 首先假设
// 求[0 - 4]的最大利润
// 假设 P[4] - P[0] > 0
// 若[0 - 4]被划分成两段
// P[2] - P[0] P[4] - P[3]
// P[4] - P[0] | P[4] - (P[3] - P[2]) - P[0]
// 假设[0 - 4]单调
// 则P[4] - P[0]为最大利润，若不单调则不是最大利润

// 所以考虑贪心算法，确定单调区间
// 加和即为最大利润

// 总结
// 不断寻找单调区间，加和

// 观察得到哈
// 单调区间 P[4] - P[0] = P[4] - P[3] + P[3] - P[2] + P[2] - P[1] + P[1] - P[0]
// 所以代码上 
// profit += (prices[cur + 1] - prices[cur])
// ++cur;

// 不是单调区间不产生利润
// 所以不用处理

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> prices = {1,4,2,5};
	cout << solution.maxProfit(prices) << endl;
	return 0;
}