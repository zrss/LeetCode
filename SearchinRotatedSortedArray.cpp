/*
    One time AC 4ms
    here must be two part and at least one part is in increasing order
    so we locate the increasing part if the target in this part then
    we can use binary search to find it
    if not just search other part
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();

        while (s < e) {
        	int mid = (s + e) >> 1;
        	if (nums[mid] == target) {
        		return mid;
        	}

    		if (nums[s] < nums[mid]) {
                if (target < nums[s] || target > nums[mid]) {
                    s = mid + 1;
                } else if (target < nums[mid]) {
                    return binarySearch(nums, target, s, mid);
                }
            } else {
                if (target < nums[mid] || target > nums[e - 1]) {
                    e = mid;
                } else {
                    return binarySearch(nums, target, mid + 1, e);
                }
            }
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int target, int s, int e) {
        while (s < e) {
            int mid = (s + e) >> 1;
            if (nums[mid] == target) {
                return mid;
            }

            if (target < nums[mid]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
    vector<int> nums = {4,5,6,1};
    cout << solution.search(nums, 3) << endl;
	return 0;
}