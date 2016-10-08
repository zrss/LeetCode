#include <iostream>

using namespace std;

// 注意运算符优先级

class Solution {
public:
    bool isPowerOfFour(int num) {
		return num > 0 && ((num & (num - 1)) == 0) && ((num & 0xAAAAAAAA) == 0);
    }
};

int main() {
	Solution solution;
	cout << solution.isPowerOfFour(16) << endl;
	return 0;
}
