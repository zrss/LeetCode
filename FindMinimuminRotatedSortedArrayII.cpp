#include <iostream>
#include <vector>

using namespace std;

// s mid e
// s < mid < e return s
// s < mid > e (mid, e]
// s == mid > e (mid, e]
// s < mid == e return s
// s > mid < e (s, mid]
// s == mid < e return mid

// 合并状态
// s == mid == e 不能判断

// s < mid <= e return s
// s <= mid < e return s
// 合并 s <= mid <= e

// s <= mid > e (mid, e]
// s > mid < e (s, mid]

// 合并 mid > e
//     mid < e

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = (s + e) >> 1;
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                int minValue = nums[s];
                for (int i = s + 1; i <= e; ++i) {
                    minValue = min(minValue, nums[i]);
                }
                return minValue;
            }

            if (nums[s] <= nums[mid] && nums[mid] <= nums[e]) {
                return nums[s];
            }

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                ++s;
                e = mid;
            }
        }

        return nums[s];
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> nums = {7,7,7,1};
    cout << solution.findMin(nums) << endl;
    return 0;
}