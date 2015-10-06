#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
    	if (m == 0 || n == 0) {
    		return 0;
    	}
    	
    	vector<vector<int>> d(m, vector<int>(n, 1));

    	for (int i = 1; i < m; ++i) {
    		for (int j = 1; j < n; ++j) {
    			d[i][j] = d[i - 1][j] + d[i][j - 1];
    		}
    	}

    	return d[m - 1][n - 1];
    }
};

int main() {
	Solution solution;
	cout << solution.uniquePaths(3, 3) << endl;
	return 0;
}