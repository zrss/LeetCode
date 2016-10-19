#include <vector>
#include <queue>

using namespace std;

// 直接的 BFS

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = m > 0 ? board[0].size() : 0;

        if (m == 0 || n == 0)
            return 0;

        int rel = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    visited[i][j] = true;
                    ++rel;
                    bfs(board, visited, i, j);
                }
            }
        }

        return rel;
    }

    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        int dirX[] = {-1, 0, 1, 0};
        int dirY[] = {0, 1, 0, -1};

        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        q.push(make_pair(x, y));

        while (!q.empty()) {
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int tx = nx + dirX[i];
                int ty = ny + dirY[i];

                if (tx >= 0 && tx < m && ty >= 0 && ty < n && board[tx][ty] == 'X' && !visited[tx][ty]) {
                    visited[tx][ty] = true;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}