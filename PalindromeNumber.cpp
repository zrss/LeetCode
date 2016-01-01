#include <iostream>

using namespace std;

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