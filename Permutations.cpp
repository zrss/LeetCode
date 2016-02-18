#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        set<int> visit;
        vector<int> cur;

        helper(res, nums, visit, cur, 0);

        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& nums, set<int>& visit, vector<int>& cur, int l) {
    	if (l == nums.size()) {
    		res.push_back(cur);
    		return;
    	}

    	for (auto itr : nums) {
    		auto exist = visit.find(itr);
    		if (exist == visit.end()) {
    			auto pair = visit.insert(itr);
    			cur.push_back(itr);
    			helper(res, nums, visit, cur, l + 1);
    			visit.erase(pair.first);
    			cur.pop_back();
    		}
    	}

    	return;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {2, 3, 1};
	solution.permute(nums);
	return 0;
}