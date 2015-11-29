#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	if (k <= 0) {
    		return false;
    	}

    	unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
        	auto itr = map.find(nums[i]);
        	if (itr != map.end()) {
        		if (i - (itr->second) <= k) {
        			return true;
        		} else {
        			itr->second = i;
        		}
        	} else {
        		map.insert(pair<int, int>(nums[i], i));
        	}
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1, 2, 3, 4};
	cout << solution.containsNearbyDuplicate(nums, 2) << endl;
	return 0;
}