// 模拟的思路
// Time O(logN)
// Space O(n)

// Memory Limit Exceeded

class Solution {
public:
	int lastRemaining(int n) {
		vector<int> nums(n, 0);
		for (int i = 0; i < n; ++i) {
			nums[i] = i + 1;
		}

		int remain = n;
		int start = 0;
		bool forward = true;
		
		while (remain > 1) {
			int t = n - 1;
			int i = t - 1;
			if (!(remain & 1) && forward) { // even and forward
				--t;
				--i;
			}

			while (i >= start) {
				swap(nums[i], nums[t--]);
				i -= 2;
			}

			remain -= (t - start + 1);
			start = t + 1;

			forward = !forward;
		}
		
		return nums[n - 1];
	}
};