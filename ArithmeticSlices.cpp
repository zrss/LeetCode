// 扫描连续的等差数列
// >= 3 为一个结果
// 等差数列长度为 len
// 则结果数为 (len - 3 + 1) + (len - 3) + ... + 1
// 所以为 (len - 2) * (len - 1) / 2
// 即 n * (n + 1) / 2

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)
			return 0;

		int len = A.size();
		int cur = 1;
		int step;

		bool init = true;

		int rel = 0;
		int curArithmeticLen = 1;

		while (cur < len) {
			if (init || A[cur] - A[cur - 1] == step) {
				step = A[cur] - A[cur - 1];
				++curArithmeticLen;
				init = false;
			}
			else {
				if (curArithmeticLen >= 3) {
					rel += (((curArithmeticLen - 2) * (curArithmeticLen - 1)) >> 1);
				}
				curArithmeticLen = 1;
				init = true;
				--cur; // pay attention
			}
			++cur;
		}

		if (curArithmeticLen >= 3) {
			rel += (((curArithmeticLen - 2) * (curArithmeticLen - 1)) >> 1);
		}

		return rel;
	}
};