#include <iostream>
#include <vector>

using namespace std;

// 思路1：暴力枚举，尝试遍历1-n个数，每次遍历n+1遍
// 思路2：鸽巢原理，假设1-n区间内，比n/2大的数，还大于n/2，则重复的数字处于n/2 - n 之间，反之则处于1 - n/2之间
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
	    int n = nums.size() - 1;
	    int low = 1;
	    int high = n;
	    int mid;

	    while (low < high) {
	        mid = (low + high) >> 1;

	        int count = 0;
	        for (int num : nums) {
	            if (num <= mid) ++count;
	        }

	        if (count > mid)
	        	high = mid;
	        else
	        	low = mid + 1;
	    }

	    return low;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}