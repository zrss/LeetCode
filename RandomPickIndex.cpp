// k = 1 蓄水池抽样算法
// 1 / alpha 概率替换抽样数字

class Solution {
public:
	Solution(vector<int> nums): nums(nums) {
	}

	int pick(int target) {
		int resultIndex;
		int alpha = 1;
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			if (nums[i] == target) {
				// 蓄水池替换
				if (rand() % alpha == 0) {
					resultIndex = i;
				}
				++alpha;
			}
		}

		return resultIndex;
	}

private:
	vector<int> nums;
};