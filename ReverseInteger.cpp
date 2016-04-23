#include <iostream>
#include <climits>

using namespace std;

// 注意溢出判断
// <= INT_MAX / 10
// <= INT_MAX - lb

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

            if (tmp <= INT_MAX / 10) {
                tmp *= 10;
                if (tmp <= INT_MAX - lb) {
                    tmp += lb;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }

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