#include <iostream>
#include <vector>

using namespace std;

// 二分查找
// 注意结束条件

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int line = 0;

        while (line >= 0 && line < matrix.size()) {
	        int s = 0;
        	int e = matrix[line].size();
	        while (s < e) {
	        	int mid = (s + e) >> 1;
	        	if (matrix[line][mid] == target) {
	        		return true;
	        	}
	        	if (matrix[line][mid] < target) {
	        		s = mid + 1;
	        	} else {
	        		e = mid;
	        	}
	        }
	        if (s != 0) {
	        	++line;
	        } else {
	        	break;
	        }
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<int>> matrix = {{1,   4,  7, 11, 15}, {2,   5,  8, 12, 19}, {3,   6,  9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
	cout << solution.searchMatrix(matrix, 5) << endl;
	cout << solution.searchMatrix(matrix, 20) << endl;
	return 0;
}