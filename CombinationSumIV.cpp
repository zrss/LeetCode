#include <iostream>
#include <vector>

using namespace std;

// classic problem
// infinite backpack
// O(n^2)

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> d(target + 1, 0);
        d[0] = 1;
        for (int i = 1; i <= target; ++i) {
        	for (int j = 0; j < nums.size(); ++j) {
        		if (nums[j] <= i) {
        			d[i] += d[i - nums[j]];
        		}
        	}
        }
        return d[target];
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1, 2, 3};
	cout << solution.combinationSum4(nums, 1) << endl;
	return 0;
}