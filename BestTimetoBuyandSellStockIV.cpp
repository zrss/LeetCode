#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 动态规划
// 状态i：表示交易次数
// 状态j：表示第j天
// T[i, j]：表示在i, j状态下的最大利润

// T[i, j] = max {
//     T[i, j - 1], j天不发生交易
//     prices[j] - prices[m] + T[i - 1, m], j天与m天发生交易, m in [0, j - 1]
// }

// 最外层遍历
// i in [1, k]
// j in [1, n]
// m in [1, j - 1]

// 可以优化
// 如 k > n/2 时，问题变成交易次数不限，因为大交易次数为 n / 2

// 里层 m 可以优化
// prices[j] + (T[i - 1, m] - prices[m]) m < j

// temp = max(temp, T[i - 1, j - 1] - prices[j - 1])
// T[i, j] = max(T[i, j - 1], temp + prices[j])


class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int maxValue = 0;

		if (k >= ((int)prices.size() >> 1)) {
			for (int i = 1; i < prices.size(); ++i) {
				maxValue += max(prices[i] - prices[i - 1], 0);
			}
			return maxValue;
		}

		vector<vector<int>> T(k + 1, vector<int>(prices.size() + 1, 0));
		for (int i = 1; i <= k; ++i) {
			int temp = INT_MIN;
			for (int j = 1; j <= prices.size(); ++j) {
				T[i][j] = max(T[i][j - 1], temp + prices[j - 1]);
				temp = max(temp, T[i - 1][j - 1] - prices[j - 1]); // j - 1，数组下标
			}
		}

		return T[k][prices.size()];
	}
};

//int main() {
//	Solution solution;
//	vector<int> prices = { 3, 2, 6, 5, 0, 3 };
//	cout << solution.maxProfit(2, prices) << endl;
//	return 0;
//}