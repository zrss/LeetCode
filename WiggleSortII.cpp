#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() <= 1) {
			return;
		}

		// 画图分析
		// 类似一个阶梯状的图形
		// 偶数情况下，n / 2 个数
		// 奇数情况下，n / 2 个大数，n / 2 - 1 个小数
		// PS：逆序

		vector<int> tmp(nums);
		sort(tmp.begin(), tmp.end());

		int cnt = nums.size();
		int smallStart = cnt & 1 ? cnt >> 1 : (cnt >> 1) - 1;
		int bigStart = cnt - 1;

		int curCnt = 0;
		while (curCnt < nums.size()) {
			nums[curCnt++] = tmp[smallStart--];
			if (curCnt < nums.size()) {
				nums[curCnt++] = tmp[bigStart--];
			}
		}
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1,2,3,4,5,6};

	solution.wiggleSort(nums);
	return 0;
}