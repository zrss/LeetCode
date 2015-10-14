#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	sort(nums.begin(), nums.end());

        vector<vector<int>> rel;
        rel.push_back(vector<int>());

        vector<int> tmp;
        aux(rel, tmp, nums, 0);

        return rel;
    }

    void aux(vector<vector<int>>& rel, vector<int>& tmp, vector<int>& nums, int curIndex) {
        for (int i = curIndex; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            rel.push_back(tmp);
            aux(rel, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution solution;
    vector<vector<int>> rel = solution.subsets(nums);
    for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
        for (auto each = itr->begin(); each != itr->end(); ++each) {
            cout << *each << " ";
        }
        cout << endl;
    }
	return 0;
}