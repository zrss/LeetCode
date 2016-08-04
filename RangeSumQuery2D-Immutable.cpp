#include <iostream>
#include <vector>

using namespace std;

// 思路直接
// 每个格子存储其左上方的矩阵和包括当前格子
// left_up up
// left    right_down

// left_up 即为 row1 col1 确定
// up      即为 row1 col2 确定
// left    即为 row2 col1 确定

// 注意 left_up 重叠
// 以及边界

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
    	// 你在逗我吗 matrix = []
    	if (matrix.size() != 0) {
    		index_ptr = new vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
    	} else {
    		index_ptr = new vector<vector<int>>(matrix.size(), vector<int>());
    	}

    	vector<vector<int>>& index = *index_ptr;

    	int h = matrix.size();
    	int w = matrix.size() == 0 ? 0 : matrix[0].size();

        int sum = 0;
        for (int i = 0; i < w; ++i) {
        	sum += matrix[0][i];
        	index[0][i] = sum;
        }

        for (int i = 1; i < h; ++i) {
        	int sum = 0;
        	for (int j = 0; j < w; ++j) {
        		sum += matrix[i][j];
        		index[i][j] = (sum + index[i - 1][j]);
        	}
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    	vector<vector<int>>& index = *index_ptr;

    	int h = index.size();
    	int w = index.size() == 0 ? 0 : index[0].size();

    	if (row1 >= h || col1 >= w || row2 >= h || col2 >= w || row1 < 0 || col1 < 0 || col2 < 0) {
    		return 0;
    	}

    	int left_up = 0;
    	int left = 0;
    	int up = 0;

    	if (row1 != 0 && col1 != 0) {
    		left_up = index[row1 - 1][col1 - 1];
    	}

    	if (row1 != 0) {
    		up = index[row1 - 1][col2];
    	}
    	if (col1 != 0) {
    		left = index[row2][col1 - 1];
    	}

/*    	cout << index[row2][col2] << endl;
    	cout << left_up << endl;
    	cout << left << endl;
    	cout << up << endl;*/

    	return index[row2][col2] + left_up - left - up;
    }

    ~NumMatrix() {
    	delete index_ptr;
    }

private:
	vector<vector<int>>* index_ptr;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(int argc, char const *argv[]) {
	vector<vector<int>> matrix = {{1}, {-7}};
	NumMatrix numMatrix(matrix);
	cout << numMatrix.sumRegion(1, 0, 1, 0) << endl;
	return 0;
}