#include <iostream>
#include <vector>

using namespace std;

// 简单粗暴DP
// dp[i]，表示i总值所需要花费的最小硬币数
// dp[i] = min(dp[i - coins[k]]) + 1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
	    vector<int> dp(amount + 1, amount + 1);

	    dp[0] = 0;
	    
	    for (int i = 1; i <= amount; ++i) {
	        for (int k = 0; k < coins.size(); ++k) {
	            if (coins[k] <= i) {
	            	dp[i] = min(dp[i], dp[i - coins[k]] + 1);
	            }
	        }
	    }

	    return dp[amount] > amount ? -1 : dp[amount];
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> coins = {2};
	cout << solution.coinChange(coins, 3) << endl;
	return 0;
}
