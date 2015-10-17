#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rel;

        sort(nums.begin(), nums.end());

        int cnt = nums.size();

        int d = 0;

        while (d < cnt - 3) {
        	int x = d + 1;

        	while (x < cnt - 2) {
				int y = x + 1;
	        	int z = cnt - 1;

	        	while (y < z) {
	        		int diff = nums[d] + nums[x] + nums[y] + nums[z] - target;

	        		//cout << d << " " << x << " " << y << " " << z << " " << endl;

	        		if (!diff) {
	        			vector<int> cur = {nums[d], nums[x], nums[y], nums[z]};
	        			rel.push_back(cur);

	        			do {
	        				++y;
	        			} while (y < z && (nums[y] == nums[y - 1]));

	        			do {
	        				--z;
	        			} while (y < z && (nums[z] == nums[z + 1]));

	        		} else if (diff < 0) {
	        			++y;
	        		} else {
	        			--z;
	        		}
	        	}

        		//cout << "debug x: " << d << " " << x << " " << y << " " << z << " " << endl;

	        	do {
	        		++x;
	        	} while (x < cnt - 2 && nums[x] == nums[x - 1]);
        	}

        	do {
        		++d;
        	} while (d < cnt - 3 && nums[d] == nums[d - 1]);
        }

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	vector<vector<int>> rel = solution.fourSum(nums, 0);

	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}