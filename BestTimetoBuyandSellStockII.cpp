#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int cnt = prices.size();
    	int profit = 0;

    	for (int i = 1; i < cnt; ++i) {
    		int diff = prices[i] - prices[i - 1];
    		if (diff > 0) {
    			profit += diff;
    		}
    	}

    	return profit;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> prices = {4, 3, 2, 6, 7, 4, 10, 11, 12};
	cout << solution.maxProfit(prices) << endl;
	return 0;
}