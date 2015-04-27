/* Leetcode 200 two try AC 26MS */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct coordinate {
  coordinate(int x, int y):x(x), y(y) {}

  int x;
  int y
;};

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
      int islands = 0;
      int row = grid.size();

      if (row == 0) { // don't forget this can be 0
        return 0;
      }

      int col = grid[0].size();

      vector<vector<bool>> subs(row, vector<bool>(grid[0].size(), false));

      stack<coordinate> stack;

      for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
          if (!subs[i][j] && grid[i][j] == '1') {
            stack.push(coordinate(i, j));
            while (!stack.empty()) {
              coordinate cur = stack.top();
              stack.pop();

              // test up
              if (cur.x > 0) {
                int up = cur.x - 1;
                if (grid[up][cur.y] == '1' && !subs[up][cur.y]) {
                  stack.push(coordinate(up, cur.y));
                  subs[up][cur.y] = true;
                }
              }

              // test down
              if (cur.x < row - 1) {
                int down = cur.x + 1;
                if (grid[down][cur.y] == '1' && !subs[down][cur.y]) {
                  stack.push(coordinate(down, cur.y));
                  subs[down][cur.y] = true;
                }
              }

              // test left
              if (cur.y > 0) {
                int left = cur.y - 1;
                if (grid[cur.x][left] == '1' && !subs[cur.x][left]) {
                  stack.push(coordinate(cur.x, left));
                  subs[cur.x][left] = true;
                }
              }

              // test right
              if (cur.y < col - 1) {
                int right = cur.y + 1;
                if (grid[cur.x][right] == '1' && !subs[cur.x][right]) {
                  stack.push(coordinate(cur.x, right));
                  subs[cur.x][right] = true;
                }
              }
            }
            ++islands;
          }
        }
      }

      return islands;
    }
};

int main(int argc, char const *argv[]) {
  vector<vector<char>> grid;

  Solution solution;
  cout << solution.numIslands(grid) << endl;

  return 0;
}
