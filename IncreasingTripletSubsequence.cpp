// 参考 LIS 的优化解法
// 因为最大长度为 3，因此寻找合适位置的复杂度是 O(1) 的

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3) {
			return false;
		}

		int first = INT_MAX;
		int second = INT_MAX;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > second) {
				return true;
			}
			else {
				if (nums[i] < first) {
					first = nums[i];
				}
				else if (nums[i] != first && nums[i] < second) {
					second = nums[i];
				}
			}
		}

		return false;
	}
};