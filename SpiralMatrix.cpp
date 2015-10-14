#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> rel;
    	if (matrix.size() == 0) {
    		return rel;
    	}

    	int sR = 0;
    	int eR = matrix.size();
    	int sC = 0;
    	int eC = matrix[0].size();

    	int r = 0;
    	int c = 0;

    	int lenR = eR - sR;
    	int lenC = eC - sC;

    	while (lenR > 1 &&  lenC > 1) {
    		for (; c < eC - 1; ++c) {
    			rel.push_back(matrix[r][c]);
    		}
    		for (; r < eR - 1; ++r) {
    			rel.push_back(matrix[r][c]);
    		}
    		for (; c > sC; --c) {
    			rel.push_back(matrix[r][c]);
    		}
    		for (; r > sR; --r) {
    			rel.push_back(matrix[r][c]);
    		}

    		++sR;
    		--eR;
    		++sC;
    		--eC;

    		++r;
    		++c;

    		lenR = eR - sR;
    		lenC = eC - sC;
    	}

    	if (lenR == 1) {
    		for (; c < eC; ++c) {
    			rel.push_back(matrix[r][c]);
    		}
    	} else if (lenC == 1) {
    		for (; r < eR; ++r) {
    			rel.push_back(matrix[r][c]);
    		}
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> r1 = {1, 2};
	vector<int> r2 = {3, 4};
	vector<vector<int>> matrix = {r1, r2};
	vector<int> rel = solution.spiralOrder(matrix);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}