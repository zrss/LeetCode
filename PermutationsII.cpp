#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        unordered_map<int, int> map;
        for (auto val : nums) {
        	auto itr = map.find(val);
        	if (itr == map.end()) {
        		map.insert(pair<int, int>(val, 1));
        	} else {
        		++(itr->second);
        	}
        }

        vector<int> cur;

        helper(res, map, cur, 0, nums.size());

        return res;
    }

    void helper(vector<vector<int>>& res, unordered_map<int, int>& map, vector<int>& cur, int l, int cnt) {
    	if (l == cnt) {
    		res.push_back(cur);
    		return;
    	}

        for (auto itr = map.begin(); itr != map.end(); ++itr) {
            if (itr->second > 0) {
                --(itr->second);
                cur.push_back(itr->first);
                helper(res, map, cur, l + 1, cnt);
                ++(itr->second);
                cur.pop_back();
            }
        }

    	return;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
    vector<int> nums = {1,1,2};
    vector<vector<int>> rel = solution.permuteUnique(nums);
    for (auto each : rel) {
        for (auto itr : each) {
            cout << itr << " ";
        }
        cout << endl;
    }
	return 0;
}