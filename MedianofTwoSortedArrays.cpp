#include <iostream>
#include <vector>

using namespace std;

// 转换为寻找第k大数问题
// 区间均为[,)
// 假设从两段中各取一段，使得两段长度和为k
// n1: 0 ----- pa - 1 ----- e1
// n2: 0 ----- pb - 1 ----- e2
// pa + pb = k
//
// 如果
// n2[pb - 1] > n1[pa - 1]
// 则k只可能在
// pa ------ e1
// 0  ------ pb
//
// 再在剩下的数中找第(k - pa)大的数即可(因为已经有pa个数在前k个数中，所以减掉)
//
// n2[pb - 1] < n1[pa - 1]
// 则k只可能在
// 0  ------ pa
// pb ------ e2
//
// 再在剩下的数中找第(k - pb)大的数即可(因为已经有pb个数在前k个数中，所以减掉)
//
// n2[pb - 1] == n1[pa - 1]
// 说明n1[pa - 1]即为第k大的元素
//
// 由此可以得到一个递归搜索算法
//
// 结束条件
// 当其中一段为空时
// 返回另一段的第k个元素
//
// 特殊情况
// 当两段长度均为1时，k为1时
// 返回两段中较小的元素
//
// 为了达到时间复杂度log(m + n)的要求
// pa长度取min(k >> 1, pa)
// 另一段长度取(k - pa)即可
//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total & 1) {
            return findkthElement(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (total >> 1) + 1);
        } else {
            return (findkthElement(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (total >> 1)) +
                findkthElement(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (total >> 1) + 1)) / 2.0;
        }
    }

    int findkthElement(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int k) {
        int l1 = e1 - s1;
        int l2 = e2 - s2;

        if (l1 == 0) {
            return nums2[k - 1];
        }

        if (l2 == 0) {
            return nums1[k - 1];
        }

        // 特殊情况
        // [4]
        // [3]
        // k == 1时
        if (l1 == l2 && l1 == 1) {
            if (k == 1) {
                return min(nums1[s1], nums2[s2]);
            }
        }

        if (l1 > l2) {
            return findkthElement(nums2, s2, e2, nums1, s1, e1, k);
        }

        int el1 = min((k >> 1), l1);
        int el2 = k - el1;

        int ne1 = s1 + el1;
        int ne2 = s2 + el2;

        if (nums1[ne1 - 1] > nums2[ne2 - 1]) {
            return findkthElement(nums1, s1, ne1, nums2, ne2, e2, k - (ne2 - s2));
        } else if (nums1[ne1 - 1] < nums2[ne2 - 1]) {
            return findkthElement(nums1, ne1, e1, nums2, s2, ne2, k - (ne1 - s1));
        } else {
            return nums1[ne1 - 1];
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums1 = {1,5,9};
	vector<int> nums2 = {2};
	cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}