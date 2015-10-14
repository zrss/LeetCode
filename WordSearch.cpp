#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (aux(board, word, visited, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool aux(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited,
    		int cur, int i, int j) {

    	if (cur == word.length()) {
    		return true;
    	}

    	if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) {
    		return false;
    	}

    	bool match = (word[cur] == board[i][j]);

    	if (match && !visited[i][j]) {
    		visited[i][j] = true;

	    	if (aux(board, word, visited, cur + 1, i - 1, j)) {
    			return true;
    		}

    		if (aux(board, word, visited, cur + 1, i, j - 1)) {
    			return true;
    		}

    		if (aux(board, word, visited, cur + 1, i + 1, j)) {
    			return true;
    		}

    		if (aux(board, word, visited, cur + 1, i, j + 1)) {
    			return true;
    		}

    		visited[i][j] = false;
    	}

    	return false;
    }
};

int main() {
	vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
	Solution solution;
	cout << solution.exist(board, "ABCCED") << endl;
	return 0;
}