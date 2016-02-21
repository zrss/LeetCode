#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int rel = 0;

        helper(rel, board, 0, n);

        return rel;
    }

    void helper(int& rel, vector<string>& board, int cur, int n) {
    	if (cur == n) {
            ++rel;
    		return;
    	}

    	for (int i = 0; i < n; ++i) {
    		if (check(board, cur, i)) {
    			board[cur][i] = 'Q';
    			helper(rel, board, cur + 1, n);
    			board[cur][i] = '.';
    		}
    	}
    }

    bool check(vector<string>& board, int x, int y) {
    	// col
    	int r = x;
    	--r;

    	while (r >= 0) {
    		if (board[r][y] != '.') {
    			return false;
    		}
    		--r;
    	}

    	// left up
    	r = x;
    	int c = y;

    	--r;
    	--c;

    	while (r >= 0 && c >= 0) {
    		if (board[r][c] != '.') {
    			return false;
    		}
    		--r;
    		--c;
    	}

    	// right up
    	r = x;
    	c = y;

    	--r;
    	++c;

    	while (r >= 0 && c < board.size()) {
    		if (board[r][c] != '.') {
    			return false;
    		}
    		--r;
    		++c;
    	}

    	return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	int rel = solution.solveNQueens(4);
	cout << rel << endl;
	return 0;
}