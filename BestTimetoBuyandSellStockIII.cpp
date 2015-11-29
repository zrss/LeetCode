#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() <= 1) {
    		return 0;
    	}

    	vector<vector<int>> d(prices.size(), vector<int>(prices.size(), 0));

    	int len = prices.size();

    	for (int l = 2; l <= len; ++l) {
    		for (int i = 0; i <= len - l; ++i) {
    			int j = i + l - 1;
    			int max = d[i][j - 1];

    			for (int x = i; x < j; ++x) {
    				if (prices[j] - prices[x] > max) {
    					max = prices[j] - prices[x];
    				}
    			}

    			d[i][j] = max;
    		}
    	}

    	int max = d[0][len - 1];

    	for (int s = 1; s < len - 1; ++s) {
    		int tmp = d[0][s] + d[s + 1][len - 1];
    		if (tmp > max) {
    			max = tmp;
    		}
    	}

    	return max;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> prices = {1,2,3,4};
	cout << solution.maxProfit(prices) << endl;
	return 0;
}