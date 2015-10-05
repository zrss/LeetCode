#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;

        for (int r = 0; r < matrix.size(); ++r) {
        	for (int c = 0; c < matrix[r].size(); ++c) {
        		if (matrix[r][c] == 0) {
        			row.insert(r);
        			col.insert(c);
        		}
        	}
        }

        for (auto itr = row.begin(); itr != row.end(); ++itr) {
        	int r = *itr;
        	for (int c = 0; c < matrix[r].size(); ++c) {
        		matrix[r][c] = 0;
        	}
        }

        for (auto itr = col.begin(); itr != col.end(); ++itr) {
        	int c = *itr;
        	for (int r = 0; r < matrix.size(); ++r) {
        		matrix[r][c] = 0;
        	}
        }
    }
};

int main() {
	vector<int> r1 = {1, 2, 0};
	vector<int> r2 = {0, 5, 6};

	vector<vector<int>> matrix = {r1, r2};

	Solution solution;
	solution.setZeroes(matrix);

	for (auto itr = matrix.begin(); itr != matrix.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}