#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1) {
    		return 0;
    	}

        vector<vector<int>> d(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        d[0][0] = 1;

        for (int i = 1; i < obstacleGrid[0].size(); ++i) {
        	if (obstacleGrid[0][i - 1] == 1) {
        		obstacleGrid[0][i] = 1;
        	} else if (obstacleGrid[0][i] == 0) {
        		d[0][i] = 1;
        	}
        }

        for (int i = 1; i < obstacleGrid.size(); ++i) {
        	if (obstacleGrid[i - 1][0] == 1) {
        		obstacleGrid[i][0] = 1;
        	} else if (obstacleGrid[i][0] == 0) {
        		d[i][0] = 1;
        	}
        }

        for (int i = 1; i < obstacleGrid.size(); ++i) {
        	for (int c = 1; c < obstacleGrid[0].size(); ++c) {
        		if (obstacleGrid[i][c] == 0) {
        			d[i][c] = d[i - 1][c] + d[i][c - 1];
        		}
        	}
        }

        return d[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main() {
	vector<int> r1 = {0, 0, 0};
	vector<int> r2 = {0, 1, 0};
	vector<int> r3 = {0, 0, 0};

	vector<vector<int>> obstacleGrid= {r1, r2, r3};

	Solution solution;
	cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}