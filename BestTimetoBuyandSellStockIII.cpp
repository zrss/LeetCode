#include <iostream>
#include <vector>

using namespace std;

// 因为最多只能交易两次
// 即一个区间只能最多被划分为两个子区间

// 如果只考虑交易一次的情况
// 那么只需从左到右扫描一遍，可以记录到i位置时的最大利润

// 从右到左扫描一遍，可以记录在不低于j位置时的*最大利润*
// 这样左右区间加和，即可求得最大利润值

// 如何求一次交易的最大利润
// O(n)算法，一次交易只和当前扫描到的最小价值，和最大价值相关

// forward[i]
// backward[j]

// backward可以空间优化不需要
// 只需要记录最大卖出价格

// 当然细节上还可以进一步精简代码
// 比如forward[len]，就是不分区间时的最大利润
// 节省多出的判断

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() == 0) {
    		return 0;
    	}

    	vector<int> forward(prices.size(), 0);

    	int minBuy = prices[0];
    	for (int i = 1; i < prices.size(); ++i) {
    		forward[i] = max(prices[i] - minBuy, forward[i - 1]);
    		minBuy = min(minBuy, prices[i]);
    	}

    	int relProfit = forward[forward.size() - 1];
    	int maxBuy = prices[prices.size() - 1];

    	for (int j = prices.size() - 2; j >= 1; --j) {
    		relProfit = max(relProfit, maxBuy - prices[j] + forward[j - 1]);
    		maxBuy = max(maxBuy, prices[j]);
    	}

		return relProfit;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> prices = {3,2,6,5,0,3};
	cout << solution.maxProfit(prices) << endl;
	return 0;
}