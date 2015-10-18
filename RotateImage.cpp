/**
	how to do it in place
	for example n = 4
	[0, 0] <-> [3, 0] <-> [3, 3] <-> [0, 3]
	denote [x, y]
	then next one will be
	[n - y - 1, x]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	int r = n >> 1;
    	for (int i = 0; i < r; ++i) {
    		for (int j = i; j < n - i - 1; ++j) {
	    		swap(matrix[i][j], matrix[n - j - 1][i]);
	    		swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
	    		swap(matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1]);
    		}
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> r1 = {};
	vector<vector<int>> m = {r1};
	solution.rotate(m);
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}