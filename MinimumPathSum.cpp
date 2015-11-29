#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if (grid.size() == 0 || grid[0].size() == 0) {
    		return 0;
    	}

    	for (int i = 1; i < grid[0].size(); ++i) {
    		grid[0][i] += grid[0][i - 1];
    	}
    	for (int i = 1; i < grid.size(); ++i) {
    		grid[i][0] += grid[i - 1][0];
    	}

        for (int i = 1; i < grid.size(); ++i) {
        	for (int j = 1; j < grid[i].size(); ++j) {
        		grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
        	}
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> r1 = {1, 0, 8};
	vector<int> r2 = {1, 0, 3};
	vector<vector<int>> m = {r1, r2};
	cout << solution.minPathSum(m) << endl;
	return 0;
}