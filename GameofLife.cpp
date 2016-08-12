#include <iostream>
#include <vector>

using namespace std;

// < 2 die
// == 2 || == 3 live (1) to next generation (1)
// > 3 die
// == 3 && die (0) to live (1)


// after update
// live 11, 10
// die 0, 1

// genius
// 11 % 10 = 1 live case 2
// 10 % 10 = 0 die case 4
// 1 / 10 = 0 die 0 / 10 die cover case 1, case 3

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int cnt = countNeighbors(i, j, board);
                if (cnt == 3 || (cnt == 2 && board[i][j] == 1)) board[i][j] += 10;
            }
        }
        
        updateBoard(board);
    }

    int countNeighbors(int i, int j, const vector<vector<int>>& board) {
        int cnt = 0;
        for (int r = max(i - 1, 0); r <= min(i + 1, (int)board.size() - 1); r++) {
            for (int c = max(j - 1, 0); c <= min(j + 1, (int)board[0].size() - 1); c++) {
                if (i != r || j != c) cnt += board[r][c] % 10;
            }
        }
        return cnt;
    }

    void updateBoard(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = board[i][j] / 10;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}