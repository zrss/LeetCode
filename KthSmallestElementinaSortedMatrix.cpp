#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// priority queue
// pay attention to reverse

// O(k * logN)

struct Position {
	int _x;
	int _y;

	int _v;

	Position(int x, int y, int v): _x(x), _y(y), _v(v) {}

	bool operator < (const Position& p) const {
        return this->_v > p._v;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	vector<vector<bool>> in_pq(matrix.size(), vector<bool>(matrix[0].size(), false));

        priority_queue<Position> pq;
        pq.push(Position(0, 0, matrix[0][0]));

        int w = matrix[0].size();
        int h = matrix.size();

        int result = 0;

        while (k > 1) {
        	Position top = pq.top();
        	pq.pop();
        	// right
        	if (top._y + 1 < w && !in_pq[top._x][top._y + 1]) {
        		pq.push(Position(top._x, top._y + 1, matrix[top._x][top._y + 1]));
        		in_pq[top._x][top._y + 1] = true;
        	}
        	// down
        	if (top._x + 1 < h && !in_pq[top._x + 1][top._y]) {
        		pq.push(Position(top._x + 1, top._y, matrix[top._x + 1][top._y]));
        		in_pq[top._x + 1][top._y] = true;
        	}
        	--k;
        }

        return pq.top()._v;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
	cout << solution.kthSmallest(matrix, 4) << endl;
	return 0;
}