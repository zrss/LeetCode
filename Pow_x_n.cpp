#include <iostream>
#include <cmath>

using namespace std;

// recursive
// myPow(x * x, n / 2) * (if n % 2 == 0 return 1 else x)

// -2147483648

class Solution {
public:
    double myPow(double x, int n) {
    	double base = n > 0 ? x : 1 / x;
    	double result = 1;

    	long long ln = n;

    	if (ln < 0)
    		ln = -ln;

    	while (ln) {
    		if (ln & 1) {
    			result *= base;
    		}
    		base *= base;
    		ln >>= 1;
    	}

    	return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.myPow(10, -10) << endl;
	return 0;
}