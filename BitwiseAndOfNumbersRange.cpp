/* Leetcode 201 one try AC 105MS */

#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	if (m == n)
    		return m;

    	int g = m & n, rel = g;
    	int mask = ~0 << 1;
    	int pow = 1;

    	while (g) {
    		int b = g & 1;
    		if (b) {
    			int temp = n & mask;

    			if (temp >= m) {
    				rel &= ~pow;
    			}
    		}
    		mask <<= 1;
    		pow <<= 1;
    		g >>= 1;
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	std::cout << solution.rangeBitwiseAnd(1, 2147483647) << std::endl;
	return 0;
}