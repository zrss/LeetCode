#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 观察
// [1, 2, 3, 4, 5]
// [1, 2, 3, (5, 4)]
// [1, 2, (4, 3, 5)]

// 通过观察发现，从右至左找顺序对，找到之后交换，并把后续元素排序，即是下一个排列

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	// 
    	for (int i = nums.size() - 1; i >= 0; --i) {
    		for (int j = nums.size() - 1; j > i; --j) {
    			if (nums[i] < nums[j]) {
    				swap(nums[i], nums[j]);
    				sort(nums.begin() + i + 1, nums.end());
    				return;
    			}
    		}
    	}
		sort(nums.begin(), nums.end());
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1,2,3};
	solution.nextPermutation(nums);

	for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}