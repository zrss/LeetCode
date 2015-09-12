#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);

	int time = T;

	while (T--) {
		int n;
		scanf("%d", &n);

		int x, y;

		vector<vector<bool> > adj(100000, vector<bool>(100000, false));
		vector<int> colorRecord(100000, 0);

		for (int i = 0; i < n - 1; ++i) {
			scanf("%d %d", &x, &y);
			adj[x][y] = adj[y][x] = true;
		}

		int q;
		scanf("%d", &q);

		printf("Case #%d:\n", time - T);

		int rel = 1;

		for (int i = 0; i < q; ++i) {
			int type;

			scanf("%d", &type);

			if (type == 1) { // query
				printf("%d\n", rel);
			} else { // 
				int nodeId, color;
				scanf("%d %d", &nodeId, &color);

				if (colorRecord[nodeId] != color) {
					bool special = true, haveAdj = false;;

					for (int node = 1; node <= n; ++node) {
						if (adj[nodeId][node]) {
							if (colorRecord[node] == colorRecord[nodeId]) {
								++rel;
							}
							else if (colorRecord[node] == color) {
								--rel;
								special = false;
								haveAdj = true;
							}
						}
					}

					if (haveAdj && special) {
						++rel;
					}

					colorRecord[nodeId] = color;
				}
			}
		}
	}

	return 0;
}