#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int tmp = 0;
        bool positive;

        if (x < 0) {
        	positive = false;
        	x = -x;
        } else {
        	positive = true;
        }

        while (x) {
        	int lb = x % 10;
        	int ext = tmp * 10;

        	if (ext % 10 != 0) { // overflow
        		return 0;
        	}

        	int ext2 = ext + lb;
        	if (ext2 < 0) {
        		return 0;
        	}

        	tmp = ext2;
        	x /= 10;
        }

        if (!positive) {
        	return -tmp;
        }

        return tmp;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.reverse(1534236469) << endl;
	return 0;
}