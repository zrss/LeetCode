#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rel;
        if (candidates.size() == 0) {
        	return rel;
        }

        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());


    }

    bool aux(vector<int>& candidates, int curIndex, int curSum,
    		vector<int>& tmp, vector<vector<int>>& rel, int target) {

    	for (int i = 0; i < candidates.size(); ++i) {
    		
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	return 0;
}