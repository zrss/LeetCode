#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int half = len >> 1;
        bool even = !(len & 1);

        if (!even) {
            return kthElement(nums1, 0, nums2, 0, half + 1);
        } else {
            return (kthElement(nums1, 0, nums2, 0, half)
                + kthElement(nums1, 0, nums2, 0, half + 1)) * 0.5;
        }
    }

    // assert k >= 1 and k <= num1.size() + nums2.size()
    // nums1.size() > 0 || nums2.size() > 0
    int kthElement(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
        if (k == 1) {
            if (nums1.size() == 0) {
                return nums2[s2];
            }
            if (nums2.size() == 0) {
                return nums1[s1];
            }
            return min(nums1[s1], nums2[s2]);
        }

        do {
            // 保证 nums1 cur size < nums2 cur size
            if (nums1.size() - s1 > nums2.size() - s2) {
                nums1.swap(nums2);
                swap(s1, s2);
            }

            // nums1 取完了
            if (!(s1 < nums1.size())) {
                return nums2[k - 1];
            }

            int index1 = min((k >> 1) - 1 + s1, (int)nums1.size() - 1);
            int index2 = k - (index1 - s1 + 1) - 1 + s2;

            if (nums1[index1] < nums2[index2]) {
                k -= (index1 - s1 + 1); // 注意顺序
                s1 = index1 + 1;
            } else if (nums1[index1] > nums2[index2]) {
                k -= (index2 - s2 + 1);
                s2 = index2 + 1;
            } else {
                return nums1[index1];
            }
        } while (k != 1);

        if (!(s1 < nums1.size())) {
            return nums2[s2];
        } else if (!(s2 < nums2.size())) {
            return nums1[s1];
        } else {
            return min(nums1[s1], nums2[s2]);
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums1 = {10001};
	vector<int> nums2 = {10000};
	cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}