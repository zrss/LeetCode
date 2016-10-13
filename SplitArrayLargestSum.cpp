#include <vector>
#include <iostream>

using namespace std;

// 二分搜索
// 目标sum有范围

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
        	right += nums[i];
        	left = max(left, nums[i]);
        }

        while (left < right) {
        	int mid = left + ((right - left) >> 1);
        	int segments = partition(nums, mid);
        	if (segments <= m) {
        		right = mid;
        	} else {
        		left = mid + 1;
        	}
        }

        return left;
    }

    int partition(vector<int>& nums, int target) {
    	int segments = 1;
    	int sum = 0;
    	int len = nums.size();
    	for (int i = 0; i < len; ++i) {
    		sum += nums[i];
    		if (sum > target) {
    			++segments;
    			sum = nums[i];
    		}
    	}
    	return segments;
    }
};

int main(int argc, char const *argv[]) {
	return 0;
}