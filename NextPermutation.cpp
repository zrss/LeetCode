#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	// is reverse ?
    	bool reverse = true;

    	for (int i = nums.size() - 1; reverse && i > 0; --i) {
    		if (nums[i - 1] < nums[i]) {
    			reverse = false;
    		}
    	}

    	if (!reverse) {
	    	int maxIndex = -1;
    		int startIndex = nums.size() - 1;

    		for (int i = startIndex; i > maxIndex; --i) {
	        	for (int j = i - 1; j >= 0; --j) {
	        		if (nums[j] < nums[i]) {
	        			if (j > maxIndex) {
	        				maxIndex = j;
	        				startIndex = i;
	        			} else if (j == maxIndex) {
	        				if (nums[startIndex] > nums[i]) {
	        					startIndex = i;
	        				}
	        			}
	        			break;
	        		}
		        }
	        }

	        swap(nums[maxIndex], nums[startIndex]);

	        sort(nums.begin() + maxIndex + 1, nums.end());

    	} else {
        	sort(nums.begin(), nums.end());
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {2,3,1};
	solution.nextPermutation(nums);

	for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}