#include <iostream>
#include <vector>

// like a backpack problem
// d[i] = max {(i - j) * max{d[j], j}}

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> d(n + 1, 0);
        d[1] = 1;
        for (int i = 2; i <= n; ++i) {
        	for (int j = 1; j < i; ++j) {
        		d[i] = max(d[i], (i - j) * max(d[j], j));
        	}
        }
        return d[n];
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.integerBreak(50) << endl;
	return 0;
}