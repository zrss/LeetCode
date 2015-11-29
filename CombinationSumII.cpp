#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> rel;

        if (candidates.size() == 0) {
        	return rel;
        }

        sort(candidates.begin(), candidates.end());

        int curSum = 0;
        vector<int> tmp;

        aux(candidates, target, rel, tmp, curSum, 0);

        return rel;
    }

    void aux(vector<int>& candidates, int target,
    		vector<vector<int>>& rel, vector<int>& tmp, int curSum, int curIndex) {

    	for (int i = curIndex; i < candidates.size(); ++i) {
    		curSum += candidates[i];
    		tmp.push_back(candidates[i]);

    		if (curSum >= target) {
    			if (curSum == target) {
    				// unique check
    				bool unique = true;

    				for (auto itr = rel.begin(); itr != rel.end(); ++itr) {

    					bool same = true;
    					if (itr->size() == tmp.size()) {
    						for (int x = 0; x < tmp.size(); ++x) {
    							if (tmp[x] != (*itr)[x]) {
    								same = false;
    								break;
    							}
    						}
    					} else {
    						same = false;
    					}

    					if (same) {
    						unique = false;
    						break;
    					}
    				}

    				if (unique) {
	    				rel.push_back(tmp);
    				}
    			}

    			curSum -= candidates[i];
    			tmp.pop_back();

    			return;

    		} else {
    			aux(candidates, target, rel, tmp, curSum, i + 1);
    		}

			curSum -= candidates[i];
			tmp.pop_back();
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> candidates = {10,1,2,7,6,1,5};
	vector<vector<int>> rel = solution.combinationSum2(candidates, 8);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}