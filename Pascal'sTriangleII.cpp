#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
        	return vector<int>();
        }

        if (rowIndex == 0) {
        	return vector<int>(1, 1);
        }

        int pre = 0;
        int next = 1;

        vector<vector<int>> row(2, vector<int>(rowIndex + 1, 0));
        row[0][0] = 1;

        for (int i = 1; i < rowIndex + 1; ++i) {
        	row[next][0] = row[pre][0];

        	for (int j = 1; j < i; ++j) {
        		row[next][j] = row[pre][j - 1] + row[pre][j];
        	}

        	row[next][i] = row[pre][i - 1];

        	pre = (pre + 1) % 2;
        	next = (next + 1) % 2;
        }

        return row[pre];
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> rel = solution.getRow(1);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}