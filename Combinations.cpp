#include <iostream>
#include <vector>

using namespace std;

// 经典递归思路

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;

        aux(result, tmp, n, k, 0, 0);

        return result;
    }

    void aux(vector<vector<int>>& result, vector<int>& tmp, int n, int k, int c_n, int c_k) {
    	if (c_k == k) {
    		result.push_back(tmp);
    		return;
    	}

    	for (int i = c_n; i < n; ++i) {
    		tmp.push_back(i + 1);
    		aux(result, tmp, n, k, i + 1, c_k + 1);
    		tmp.pop_back();
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	auto result = solution.combine(4, 2);
	for (auto line : result) {
		for (auto each : line) {
			cout << each << " ";
		}
		cout << endl;
	}
	return 0;
}