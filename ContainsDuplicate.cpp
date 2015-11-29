#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        	auto relItr = set.find(*itr);
        	if (relItr != set.end()) {
        		return true;
        	} else {
        		set.insert(*itr);
        	}
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1, 2, 4};
	cout << solution.containsDuplicate(nums) << endl;
	return 0;
}