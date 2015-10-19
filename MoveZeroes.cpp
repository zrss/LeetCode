#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int e = nums.size();
        int i = nums.size() - 1;

        while (i >= 0) {
	        if (nums[i] == 0) {
	        	copy(nums.begin() + i + 1, nums.begin() + e, nums.begin() + i);
	        	nums[e - 1] = 0;
	        	--e;
	        }
	        --i;
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {0};
	solution.moveZeroes(nums);
	for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}