#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int n = nums.size();

    	int total = n * (n + 1) >> 1;
    	int cur = 0;

    	for (int i = 0; i < n; ++i) {
    		cur += nums[i];
    	}

    	return total - cur;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {0,1,3};
	Solution solution;
	cout << solution.missingNumber(nums) << endl;
	return 0;
}