#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if (matrix.size() == 0 || matrix[0].size() == 0) {
    		return false;
    	}

    	int row = locateRow(matrix, target);
    	if (row == -1) {
    		return false;
    	}

    	int s = 0;
    	int e = matrix[row].size();

    	while (s < e) {
    		int mid = (s + e) >> 1;
    		if (target == matrix[row][mid]) {
    			return true;
    		}
    		if (target < matrix[row][mid]) {
    			e = mid;
    		} else {
    			s = mid + 1;
    		}
    	}

    	return false;
    }

    int locateRow(vector<vector<int>>& matrix, int target) {
    	int sR = 0;
    	int eR = matrix.size();
    	int tail = matrix[0].size() - 1;

    	while (sR < eR) {
    		int midR = (sR + eR) >> 1;
    		if (target < matrix[midR][0]) {
    			eR = midR;
    		} else if (target > matrix[midR][tail]) {
    			sR = midR + 1;
    		} else {
    			return midR;
    		}
    	}

    	return -1;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> r1 = {1,3,5,7};
	vector<int> r2 = {10,11,16,20};
	vector<int> r3 = {23,30,34,50};
	vector<vector<int>> matrix = {r1,r2,r3};
	cout << solution.searchMatrix(matrix, 12) << endl;
	return 0;
}