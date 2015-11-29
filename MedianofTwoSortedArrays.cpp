#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    }

    // assert k >= 1 and k <= num1.size() + nums2.size()
    // nums1.size() > 0
    // nums2.size() > 0
    int kthElement(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
        while (k != 1) {
            if (nums1.size() - s1 > nums2.size() - s2) {
                swap(nums1, nums2);
            }

            int x = k >> 1;
            int index1 = min(x - 1 + s1, (int)nums1.size() - 1);
            int index2 = k - x - 1 + s2;

            if (nums1[index1] < nums2[index2]) {
                s1 = index1 + 1;
                k -= (index1 - s1 + 1);
            } else if (nums1[index1] > nums2[index2]) {
                s2 = index2 + 1;
                k -= (index2 - s2 + 1);
            } else {
                return nums1[index1];
            }
        }

        return min(nums1[s1], nums2[s2]);
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums1 = {1,2,3,5};
	vector<int> nums2 = {1};
	cout << solution.kthElement(nums1, 0, nums2, 0, 5) << endl;
	return 0;
}