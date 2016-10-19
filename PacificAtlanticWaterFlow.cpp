// 思路很直接 DFS 或者 BFS 都可以
// 想试试 BFS 的思路

// 一开始尝试了单点 BFS 的思路
// 果断超时了
// 即从高往低走，看是否能联通两个区域

// 看 Discuss 之后，发现可以从两个区域分别开始 BFS，即从低往高走，两个区域都能到达的点，即为可联通两个区域的点

class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> rel;
		int m = matrix.size();
		int n = m > 0 ? matrix[0].size() : 0;

		if (m == 0 || n == 0)
			return rel;

		vector<vector<bool>> pVisited(m, vector<bool>(n, false));
		queue<pair<int, int>> pQueue;
		vector<vector<bool>> aVisited(m, vector<bool>(n, false));
		queue<pair<int, int>> aQueue;

		for (int i = 0; i < m; ++i) {
			pQueue.push(make_pair(i, 0));
			pVisited[i][0] = true;
			aQueue.push(make_pair(i, n - 1));
			aVisited[i][n - 1] = true;
		}

		for (int i = 0; i < n; ++i) {
			pQueue.push(make_pair(0, i));
			pVisited[0][i] = true;
			aQueue.push(make_pair(m - 1, i));
			aVisited[m - 1][i] = true;
		}

		bfs(matrix, pVisited, pQueue);
		bfs(matrix, aVisited, aQueue);

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (pVisited[i][j] && aVisited[i][j]) {
					rel.push_back(make_pair(i, j));
				}
			}
		}

		return rel;
	}

	void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
		int dirX[] = {-1, 0, 1, 0};
		int dirY[] = {0, 1, 0, -1};

		int m = matrix.size();
		int n = matrix[0].size();

		bool touchP = false;
		bool touchA = false;

		while (!q.empty()) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int sx = tx + dirX[i];
				int sy = ty + dirY[i];

				if (sx >= 0 && sx < m && sy >= 0 && sy < n 
					&& !visited[sx][sy]
					&& matrix[tx][ty] <= matrix[sx][sy]) {

					q.push(make_pair(sx, sy));
					visited[sx][sy] = true;

				}
			}
		}
	}
};