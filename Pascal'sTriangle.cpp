#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rel;

        if (numRows <= 0) {
        	return rel;
        }

        rel.push_back(vector<int>(1, 1));

        for (int i = 1; i < numRows; ++i) {
        	vector<int> row;

        	row.push_back(rel[i - 1][0]);

        	for (int j = 1; j < i; ++j) {
        		row.push_back(rel[i - 1][j - 1] + rel[i - 1][j]);
        	}

        	row.push_back(rel[i - 1][i - 1]);

        	rel.push_back(row);
        }

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<int>> rel = solution.generate(5);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}