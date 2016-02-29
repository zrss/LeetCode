#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if (matrix.size() == 0) {
    		return 0;
    	}
    	vector<vector<int>> step(matrix.size(), vector<int>(matrix[0].size(), 0));
    	int result = 0;
    	for (int i = 0; i < matrix.size(); ++i) {
    		for (int j = 0; j < matrix[i].size(); ++j) {
    			int tmp = DFS(matrix, i, j, INT_MIN, step);
   				result = max(result, tmp);
    		}
    	}
    	return result;
    }

   	int DFS(vector<vector<int>>& matrix, int x, int y, int val, vector<vector<int>>& step) {
   		if (y < 0 || y >= matrix[0].size() || x < 0 || x >= matrix.size()) {
   			return 0;
   		}
   		if (matrix[x][y] > val) { // 当前高度大于之前的高度
   			if (step[x][y] > 0) { // 已经搜索过的路径
   				return step[x][y];
   			}
   			int result = 0;
   			// 上、右、下、左
   			for (auto each : dir) {
   				int tmp = DFS(matrix, x + each[0], y + each[1], matrix[x][y], step) + 1;
   				result = max(result, tmp);
   			}
   			step[x][y] = result; // 更新
   			return result;
   		}
   		return 0;
   	}

private:
	vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<int>> matrix = {{0,1,2}, {5,4,3}, {6,7,8}};
	cout << solution.longestIncreasingPath(matrix) << endl;
	return 0;
}