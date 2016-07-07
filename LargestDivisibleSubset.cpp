#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// I don't known how I figure it out in two days -_- but the thought just come
// sort number in increasing order

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
   		if (nums.size() == 0 || nums.size() == 1) {
   			return nums;
   		}

        sort(nums.begin(), nums.end());
        vector<int> d(nums.size(), 1);
        vector<int> previous(nums.size(), -1);

        int maxLength = 0;
        int maxPosition = 0;

        for (int i = 1; i < nums.size(); ++i) {
        	int max = 0;
        	int pos = -1; // 
        	for (int j = i - 1; j >= 0; --j) {
        		if (!(nums[i] % nums[j])) {
        			if (d[j] > max) {
        				max = d[j];
        				pos = j;
        			}
        		}
        	}
        	d[i] += max;
        	previous[i] = pos;
        	if (d[i] > maxLength) {
        		maxLength = d[i];
        		maxPosition = i;
        	}
        }

        vector<int> maxArray;
        for (int i = maxPosition; i >= 0; i = previous[i]) {
        	maxArray.push_back(nums[i]);
        }

        return maxArray;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {2, 3};
	vector<int> result = solution.largestDivisibleSubset(nums);
	for (int each : result) {
		cout << each << " ";
	}
	cout << endl;
	return 0;
}