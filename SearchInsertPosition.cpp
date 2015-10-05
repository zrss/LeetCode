#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int cnt = nums.size();
        int i = 0;
        while (i < cnt) {
        	if (target <= nums[i]) {
        		return i;
        	}
        	++i;
        }
        return i;
    }
};

int main(int argc, char const *argv[]) {
	vector<int> nums = {1,3,5,6};
	Solution solution;
	cout << solution.searchInsert(nums, 0) << endl;
	return 0;
}