#include <iostream>
#include <vector>

using namespace std;

// classic problem
// similar to longest up susequence
// O(n^2)

// but how to do it in O(n) 

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
        	return nums.size();
        }

        vector<int> len(nums.size(), 0);
        vector<bool> direct(nums.size(), false);

        len[0] = 1;
        int max_len = 1;

        for (int i = 1; i < nums.size(); ++i) {
        	if (nums[i] != nums[0]) {
        		len[i] = 2;
        		direct[i] = (nums[i] - nums[0] > 0);
        	}
        	for (int j = 1; j < i; ++j) {
        		if (nums[i] != nums[j]) { // error 1
	        		bool cur_direct = (nums[i] - nums[j] > 0);
	        		int cur_len = len[j] + 1;
	        		if (cur_direct != direct[j] && cur_len > len[i]) {
	        			len[i] = cur_len;
	        			direct[i] = cur_direct;
	        		}
        		}
        	}
        	if (len[i] > max_len) {
        		max_len = len[i];
        	}
        }

        return max_len;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1,1,2,2,2};
	cout << solution.wiggleMaxLength(nums) << endl;
	return 0;
}