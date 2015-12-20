#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool set[10];

        int row = board.size();
        if (row == 0) {
        	return false;
        }

        int col = board[0].size();

        // row
        for (int i = 0; i < row; ++i) {
        	memset(set, false, sizeof(set));
        	for (int c = 0; c < col; ++c) {
        		if (board[i][c] == '.') {
        			continue;
        		}
        		int index = board[i][c] - '0';
        		if (set[index]) {
        			return false;
        		} else {
        			set[index] = true;
        		}
        	}
        }

        // col
        for (int i = 0; i < col; ++i) {
        	memset(set, false, sizeof(set));
        	for (int r = 0; r < row; ++r) {
        		if (board[r][i] == '.') {
        			continue;
        		}
        		int index = board[r][i] - '0';
        		if (set[index]) {
        			return false;
        		} else {
        			set[index] = true;
        		}
        	}
        }

        // grid
        // 理解错题意了之前，只有9个子正方形
        for (int x = 0; x < 7; x += 3) {
        	for (int y = 0; y < 7; y += 3) {
        		if (!checkGrid(board, x, y)) {
        			return false;
        		}
        	}
        }

        return true;
    }

	bool checkGrid(vector<vector<char> >& board, int x, int y) {
		bool set[10] = {false, false, false, false, false, false, false, false, false, false};

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
        		if (board[x + i][y + j] == '.') {
        			continue;
        		}
				int index = board[x + i][y + j] - '0';
				if (set[index]) {
					return false;
				} else {
					set[index] = true;
				}
			}
		}

		return true;
	}
};

int main(int argc, char const *argv[])
{
	Solution solution;
	vector<string> mock = {"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."}
	vector<vector<char> > board;

	for (auto itr = mock.begin(); itr != mock.end(); ++itr) {
		vector<char> tmp;
		for (auto c = itr->begin(); c != itr->end(); ++c) {
			tmp.push_back(*c);
		}
		board.push_back(tmp);
	}

	cout << solution.isValidSudoku(board) << endl;

	return 0;
}