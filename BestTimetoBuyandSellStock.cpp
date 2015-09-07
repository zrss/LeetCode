#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        if (day == 0) { // check
        	return 0;
        }

        int profit = 0;
        int minBuy = prices[0];

        for (int i = 1; i < day; ++i) {
        	int tmp = prices[i] - minBuy;
        	if (tmp > profit) {
        		profit = tmp;
        	}
        	if (prices[i] < minBuy) {
        		minBuy = prices[i];
        	}
        }

        return profit;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	vector<int> prices = {2,1,1,8,10};
	cout << solution.maxProfit(prices) << endl;
	return 0;
}