#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int index = binarySearch(nums, target);

    	if (index == -1) {
    		return vector<int>{-1, -1};
    	}

    	// left bound
    	int lb = index - 1;
    	while (lb >= 0 && nums[lb] == nums[lb + 1]) {
    		--lb;
    	}
    	++lb;

    	int rb = index + 1;
    	while (rb < nums.size() && nums[rb] == nums[rb - 1]) {
    		++rb;
    	}
    	--rb;

    	return vector<int>{lb, rb};
    }

    int binarySearch(vector<int>& nums, int target) {
    	int s = 0;
    	int e = nums.size();

    	while (s < e) {
    		int mid = (s + e) >> 1;
    		if (nums[mid] == target) {
    			return mid;
    		} else if (nums[mid] > target) {
    			e = mid;
    		} else {
    			s = mid + 1;
    		}
    	}

    	return -1;
    }
};

int main() {
	Solution solution;
	vector<int> nums = {5,7,7,8,8,10};
	vector<int> rel = solution.searchRange(nums, 11);
	cout << rel[0] << " " << rel[1] << endl;
	return 0;
}