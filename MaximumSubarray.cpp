#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> d(nums.size(), 0);

        d[0] = nums[0];
        int max = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
        	if (d[i - 1] >= 0) {
        		d[i] = d[i - 1] + nums[i];
        	} else {
        		d[i] = nums[i];
        	}

        	if (d[i] > max) {
        		max = d[i];
        	}
        }

        return max;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout << solution.maxSubArray(nums) << endl;
	return 0;
}