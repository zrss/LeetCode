#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if (x == 0) {
    		return 0;
    	}

    	bool positive = x > 0;

    	long long itr = x;
    	if (!positive) {
    		itr = -itr;
    	}

    	long long low = 1;
    	long long high = itr;

    	long long mid = (low + high) >> 1;

    	while (low + 1 < high) {
    		mid = (low + high) >> 1;

    		long long times = mid * mid;
    		if (times > x) {
    			high = mid;
    		} else if (times == x) {
    			return positive ? mid : -mid;
    		} else {
    			low = mid;
    		}
    	}

    	return positive ? low : -low;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.mySqrt(0) << endl;
	return 0;
}