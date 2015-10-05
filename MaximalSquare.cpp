/* LeetCode 221 two try 524MS */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();

        if (h == 0) // ps
        	return 0;

        int w = matrix[0].size();

        int side = h > w ? w : h;

        for ( ;side > 0; --side) {
        	for (int i = 0; i <= w - side; ++i) {
        		for (int j = 0; j <= h - side; ++j) {
        			//test all 1
        			bool all = true;
        			for (int row = 0; all && row < side; ++row) {
        				for (int col = 0; all && col < side; ++col) {
        					if (matrix[j + row][i + col] == '0')
        						all = false;
        				}
        			}
        			if (all)
        				return side * side;
        		}
        	}
        }

        return 0;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	//vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

	vector<vector<char>> matrix;

	cout << solution.maximalSquare(matrix) << endl;

	return 0;
}