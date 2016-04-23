#include <iostream>

using namespace std;

// 方法1
// 直接提取每一位数字
// 即使有溢出也能正确返回false
//
// 方法2
// 用数组将每位数字存储起来再做比较

class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0) {
    	    return false;
    	}

        int value = 0;
        int tmp = x;

        while (tmp) {
        	value *= 10;
        	value += (tmp % 10);
        	tmp /= 10;
        }

        return value == x ? true : false;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.isPalindrome(122231) << endl;
	return 0;
}