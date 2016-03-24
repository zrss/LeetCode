#include <iostream>
#include <vector>

using namespace std;

// 思路1：暴力枚举，尝试遍历1 - n个数，每次遍历n + 1遍
// 思路2：鸽巢原理，假设1 - n区间内，比n/2大的数的个数，还大于n/2，则重复的数字处于n/2 - n 之间，反之则处于1 - n/2之间
// 思路3：映射找环法
// 
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
	    int n = nums.size() - 1;
	    
	    // 优化枚举
	    int low = 1;
	    int high = n;

	    int mid; // 当前枚举值

	    while (low < high) {
	        mid = (low + high) >> 1;

	        // 求<=枚举值的数的个数
	        int count = 0;
	        for (int num : nums) {
	            if (num <= mid) ++count; // 注意这里是相等
	        }

	        if (count > mid)
	        	high = mid; // 如果大于枚举值，则重复的数字在[low, mid]之间
	        else
	        	low = mid + 1; // 如果小于等于枚举值则重复的数字在[mid + 1, high]之间
	    }

	    return low;
	}

	// 假设数组中没有重复，那我们可以做到这么一点，就是将数组的下标和1到n每一个数一对一的映射起来
	// 找环算法
	// 快慢指针
	// 快指针一次走两步
	// 慢指针一次走一步
	// 若重合则有环
	// 有环之后，慢指针，新头指针，再每次走一步，相遇即是环起点

	// nums[n] = v
	// f[n] = v
	int detectCircle(vector<int>& nums) {
		int slow = 0;
		int fast = 0;

		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		int itr = 0;
		do {
			itr = nums[itr];
			slow = nums[slow];
		} while (itr != slow);

		return itr;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1,2,2};
	cout << solution.detectCircle(nums) << endl;
	return 0;
}