#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();

        if (row == 0) {
            return;
        }
        
        int col = board[0].size();

        for (int x = 0; x < row; ++x) {
            if (board[x][0] == 'O') {
                extend(x, 0, board);
            }
            if (board[x][col - 1] == 'O') {
                extend(x, col - 1, board);
            }
        }

        for (int y = 0; y < col; ++y) {
            if (board[0][y] == 'O') {
                extend(0, y, board);
            }
            if (board[row - 1][y] == 'O') {
                extend(row - 1, y, board);
            }
        }

        for (int x = 0; x < row; ++x) {
            for (int y = 0; y < col; ++y) {
                if (board[x][y] == '*') {
                    board[x][y] = 'O';
                } else {
                    board[x][y] = 'X';
                }
            }
        }
    }

    void extend(int x, int y, vector<vector<char>>& board) {
        board[x][y] = '*'; // tag

        int row = board.size();
        int col = board[0].size();

        if (x > 1 && board[x - 1][y] == 'O') { // up
            extend(x - 1, y, board);
        }
        if (y < col - 1 && board[x][y + 1] == 'O') { // right
            extend(x, y + 1, board);
        }
        if (x < row - 1 && board[x + 1][y] == 'O') { // down
            extend(x + 1, y, board);
        }
        if (y > 1 && board[x][y - 1] == 'O') { // left
            extend(x, y - 1, board);
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<char>> board;
	solution.solve(board);

	for (auto itr = board.begin(); itr != board.end(); ++itr) {
		for (auto col = itr->begin(); col != itr->end(); ++col) {
			cout << *col;
		}
		cout << endl;
	}
	return 0;
}