#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	copy_backward(nums1.begin(), nums1.begin() + m, nums1.end());

    	int itrM = n;
    	int itrN = 0;

    	int cur = 0;

    	int len = n + m;

    	while (itrN < n && itrM < len) {
    		if (nums1[itrM] < nums2[itrN]) {
    			nums1[cur++] = nums1[itrM++];
    		} else {
    			nums1[cur++] = nums2[itrN++];
    		}
    	}

    	if (itrN < n) {
    		copy(nums2.begin() + itrN, nums2.end(), nums1.begin() + m + itrN);
    	}
    }
};

int main() {
	vector<int> nums1 = {1};
	vector<int> nums2 = {};

	nums1.resize(nums1.size() + nums2.size());

	Solution solution;
	solution.merge(nums1, 1, nums2, nums2.size());

	for (auto itr = nums1.begin(); itr != nums1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}
