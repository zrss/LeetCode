#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if (n <= 0) {
    		return false;
    	}

    	return (n & (n - 1)) == 0;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.isPowerOfTwo(3) << endl;
	return 0;
}