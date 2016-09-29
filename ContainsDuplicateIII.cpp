#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

// binary search tree
// maintain a length k windows

// nlogk

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> binary_search_tree;
        for (int i = 0; i < nums.size(); ++i) {
            int to_remove_index = i - k - 1; // trap more than half hour -_-
            if (to_remove_index >= 0) {
                binary_search_tree.erase(nums[to_remove_index]);
            }
            auto itr = binary_search_tree.lower_bound(nums[i] - t);
            if (itr != binary_search_tree.end() && *itr <= ((long long)nums[i] + t)) {
                return true;
            }
            binary_search_tree.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> nums = {0, INT_MAX};
    cout << solution.containsNearbyAlmostDuplicate(nums, 1, INT_MAX) << endl;
    return 0;
}