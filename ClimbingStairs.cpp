#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int* d = new int[n + 1];
        
        d[0] = d[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
        	d[i] = d[i - 1] + d[i - 2];
        }

        int rel = d[n];

        delete [] d;

        return rel;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.climbStairs(3) << endl;
	return 0;
}