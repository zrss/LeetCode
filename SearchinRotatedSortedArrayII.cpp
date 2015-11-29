/*
    element can appear more than once
    so please pay attention to the process of locate increasing part
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return auxSearch(nums, target, 0, nums.size());
    }

    bool auxSearch(vector<int>& nums, int target, int s, int e) {
        while (s < e) {
            int mid = (s + e) >> 1;
            if (target == nums[mid]) {
                return true;
            }

            if (nums[s] < nums[mid]) {
                if (target < nums[s] || target > nums[mid]) {
                    s = mid + 1;
                } else {
                    return binarySearch(nums, target, s, mid);
                }
            } else if (nums[mid] < nums[e - 1]) {
                if (target < nums[mid] || target > nums[e - 1]) {
                    e = mid;
                } else {
                    return binarySearch(nums, target, mid + 1, e);
                }
            }

            if (nums[s] == nums[mid]) {
                if (checkSame(nums, s, mid + 1)) {
                    s = mid + 1;
                } else {
                    if (auxSearch(nums, target, s + 1, mid - 1)) {
                        return true;
                    }
                }
            }

            if (nums[mid] == nums[e - 1]) {
                if (checkSame(nums, mid, e)) {
                    e = mid;
                } else {
                    if (auxSearch(nums, target, mid + 1, e - 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    // assert nums[s] == nums[e - 1]
    bool checkSame(vector<int>& nums, int s, int e) {
        for (int i = s + 1; i < e - 1; ++i) {
            if (nums[i] != nums[s]) {
                return false;
            }
        }
        return true;
    }

    int binarySearch(vector<int>& nums, int target, int s, int e) {
        while (s < e) {
            int mid = (s + e) >> 1;
            if (nums[mid] == target) {
                return true;
            }

            if (target < nums[mid]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
    vector<int> nums = {1,1,1,3,1};
    cout << solution.search(nums, 3) << endl;
	return 0;
}