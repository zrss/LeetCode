#include <iostream>
#include <vector>
#include <limit>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());

    	int cnt = nums.size();
    	int minDiff = INT_MAX;

    	for (int x = 0; x < cnt - 2; ++x) {
    		int y = x + 1;
			int z = cnt - 1;

    		while (y < z) {
    			int diff = nums[x] + nums[y] + nums[z] - target;

    			if (!diff) {
    				return target;
    			}

    			if (diff < 0) {
    				++y;
    			} else {
    				--z;
    			}

    			if (abs(diff) < abs(minDiff)) {
    				minDiff = diff;
    			}
    		}
    	}

    	return target + minDiff;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {-1, 1, 2, -4};
	cout << solution.threeSumClosest(nums, 1) << endl;
	return 0;
}