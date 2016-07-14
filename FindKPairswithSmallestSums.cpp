// in the beginning
// I would like to sort the array and use two pointers
// to track the result
// but after some cases I found that is not enough
// I should use a d[] array to record the next one position in nums2 array

// and the problem points out that nums1 and nums2 array are rank in ascending order
// so do not need to sort them again

// time complexity O(k * n)

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int itr1 = 0;
        int itr2 = 0;
        vector<int> d(nums1.size(), 0);
        bool cont = true;

        vector<pair<int, int>> result;

        for (int r = 0; cont && r < k; ++r) {    
            int min = 0x7FFFFFFF;
            int index = -1;
            for (int i = 0; i < nums1.size(); ++i) {
                if (d[i] < nums2.size()) {
                    int tmp = nums1[i] + nums2[d[i]];
                    if (tmp <= min) {
                        min = tmp;
                        index = i;
                    }
                }
            }
            if (index != -1) {
                result.push_back(pair<int, int>(nums1[index], nums2[d[index]]));
                ++d[index];
            } else {
                cont = false;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3}; 
    vector<pair<int, int>> result = solution.kSmallestPairs(nums1, nums2, 3);
    for (pair<int, int> each : result) {
        cout << "(" << each.first << "," << each.second << ")" << " ";
    }
    cout << endl;
    return 0;
}