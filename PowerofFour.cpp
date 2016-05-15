#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
		if (num <= 0) {
			return false;
		}

        // (2^2)^n = 2^(2n)
		// 二进制中 0 的个数为偶数 
		if ((num & (num - 1)) != 0) {
			return false;
		}

		int cnt = 0;
		while (num) {
			if ((num & 1) == 0) {
				++cnt;
			}
			num >>= 1;
		}

		if (cnt & 1) {
			return false;
		}

		return true;
    }
};

int main() {
	Solution solution;
	cout << solution.isPowerOfFour(16) << endl;
	return 0;
}
