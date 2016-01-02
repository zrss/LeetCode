#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) {
			return INT_MAX;
		}

		// special case
		if (dividend == -2147483648 && divisor == -1) {
			return 2147483647;
		}

		bool positive = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));

		unsigned int pend = abs(dividend);
		unsigned int psor = abs(divisor);

		int quotient = 0;

		while (pend >= psor) {
			long long tmp = psor;

			int i = 0;
			for (; tmp <= pend; ++i) {
				tmp <<= 1;
			}

			quotient += (1 << (i - 1));
			pend -= (tmp >> 1);
		}

		return positive ? quotient : -quotient;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.divide(2147483647, 10) << endl;
	return 0;
}