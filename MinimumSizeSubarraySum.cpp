#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int minLen = nums.size();
    	bool found = false;

        for (int i = 0; i < nums.size(); ++i) {
        	int sum = nums[i];
        	int tail = i + 1;

        	int end = i + minLen;
        	if (end > nums.size()) {
        		end = nums.size();
        	}

        	for (; sum < s && tail < end; ++tail) {
        		sum += nums[tail];
        	}

        	if (sum >= s && tail - i < minLen) {
        		minLen = tail - i;
        		found = true;
        	}
        }

        if (found) {
        	return minLen;
        }
        else {
        	return 0;
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {2,3,1,2,4,80};
	cout << solution.minSubArrayLen(80, nums) << endl;
	return 0;
}