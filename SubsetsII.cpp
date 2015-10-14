#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> rel;
        vector<int> tmp;

        sort(nums.begin(), nums.end());

        rel.push_back(vector<int>());
        aux(rel, nums, tmp, 0);

        return rel;
    }

    void aux(vector<vector<int>>& rel, vector<int>& nums, vector<int>& tmp, int cur) {
    	for (int i = cur; i < nums.size(); ++i) {
    		tmp.push_back(nums[i]);
    		if (!exist(rel, tmp)) {
    			rel.push_back(tmp);
    			aux(rel, nums, tmp, i + 1); // hehe cur + 1 ? cost me 1 hour to debug
    		}
    		tmp.pop_back();
    	}
    }

    bool exist(vector<vector<int>>& rel, vector<int>& target) {
    	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
    		if (*itr == target) {
    			return true;
    		}
    	}
    	return false;
    }
};

int main() {
	vector<int> nums = {1,2,2};
	Solution solution;
	vector<vector<int>> rel = solution.subsetsWithDup(nums);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}