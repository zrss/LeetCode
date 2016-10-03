// 二分的思路
// 实际上并不用维护每个数字
// 维护序列的起始数字 start index
// 及序列的间隔即可 step

// 当剩余序列的长度为奇数时 forward 与 backward 结果相同
// 为偶数时

// 当剩余序列长度为 1 时, 退出

class Solution {
public:
	int lastRemaining(int n) {
		int start = 0;
		int step = 1;
		bool forward = true;
		int remain = n;
		
		while (remain > 1) {
			if (remain & 1 || forward) {
				start += step;
				step <<= 1;
			}
			else {
				step <<= 1;
			}
			remain >>= 1;
			forward = !forward;
		}
		
		return start + 1;
	}
};