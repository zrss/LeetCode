#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rel(n, vector<int>(n, 0));
        if (n <= 0) {
        	return rel;
        }

        int r = 0;
        int c = 0;
        int sR = 0;
        int sC = 0;
        int len = n;
        int cnt = n >> 1;
        int cur = 0;
        int i = 1;

        while (cur < cnt) {
        	for (; c < len - 1; ++c, ++i) {
        		rel[r][c] = i;
        	}
        	for (; r < len - 1; ++r, ++i) {
        		rel[r][c] = i;
        	}
        	for (; c > sC; --c, ++i) {
        		rel[r][c] = i;
        	}
        	for (; r > sR; --r, ++i) {
        		rel[r][c] = i;
        	}
        	++cur;
        	++sR;
        	++sC;
        	r = sR;
        	c = sC;
        	--len;
        }

        if (n & 1) {
        	rel[sR][sC] = i;
        }

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<int>> rel = solution.generateMatrix(6);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}