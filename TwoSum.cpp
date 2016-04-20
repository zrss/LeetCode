#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 双指针排序法
// 时间复杂度O(nlogn)，空间复杂度O(n)
// nums[start] + nums[end] > target
// --end
// < target
// ++start
// == target
// return 原下标

struct Index {
	int val;
	int index;

	Index(): val(0), index(0) {}
	Index(int v, int i): val(v), index(i) {}
};

bool cmp(const Index& i1, const Index& i2) {
	return i1.val < i2.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<Index> convert;
    	for (int i = 0; i < nums.size(); ++i) {
    		convert.push_back(Index(nums[i], i));
    	}
    	sort(convert.begin(), convert.end(), cmp);

    	vector<int> rel(2, 0);
    	int start = 0;
    	int end = (int)nums.size() - 1;

    	while (start < end) {
    		int tmp = convert[start].val + convert[end].val;
    		if (tmp > target) {
    			--end;
    		} else if (tmp < target) {
    			++start;
    		} else {
    			rel[0] = convert[start].index;
    			rel[1] = convert[end].index;
    			return rel;
    		}
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {3, 2, 4};
	auto rel = solution.twoSum(nums, 6);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}