#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.size() == 0) {
    		return 0;
    	}
    	
    	vector<int> len(nums.size(), 1);
    	int maxLen = 1;
    	for (int i = 1; i < nums.size(); ++i) {
    		for (int j = 0; j < i; ++j) {
    			if (nums[j] < nums[i]) {
    				if (len[j] + 1 > len[i]) {
    					len[i] = len[j] + 1;
    				}
    			}
    		}
    		if (len[i] > maxLen) {
    			maxLen = len[i];
    		}
    	}
    	return maxLen;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << solution.lengthOfLIS(nums) << endl;
	return 0;
}
