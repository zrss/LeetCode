#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> rel;

        if (k == 0) {
        	return rel;
        }

        int curSum = 0;
        vector<int> tmp;

        aux(k, n, 1, 1, curSum, rel, tmp);

        return rel;
    }

    void aux(int k, int n, int ith, int curIndex, int curSum, vector<vector<int>>& rel, vector<int>& tmp) {
    	if (ith > k) {
			if (curSum == n) {
				rel.push_back(tmp);
			}
    		return;
    	}

    	for (int i = curIndex; i < 10; ++i) {
    		curSum += i;
    		tmp.push_back(i);

    		aux(k, n, ith + 1, i + 1, curSum, rel, tmp);

			curSum -= i;
			tmp.pop_back();
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<int>> rel = solution.combinationSum3(3, 9);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}