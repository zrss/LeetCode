#include <iostream>
#include <vector>

using namespace std;

// H-Index 后续
// 文章的引用数有序
// 优化为logN复杂度

// 考虑二分搜索
//   s    m    e
// r[s] r[m] r[e]

// N - m 从右往左的位置

// if r[m] >= (N - m)
// 左侧
// if r[m] < (N - m)
// 右侧

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = 0;
        int e = citations.size();
        int N = citations.size();
        int maxH = 0;

        while (s < e) {
        	int m = (s + e) >> 1;
        	if (citations[m] >= (N - m)) {
        		e = m;
        	} else {
        		s = m + 1;
        	}
        	maxH = max(maxH, min(citations[m], N - m));
        }

        return maxH;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> citations = {11, 15};
	cout << solution.hIndex(citations) << endl;
	return 0;
}