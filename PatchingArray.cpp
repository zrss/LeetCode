#include <iostream>
#include <vector>

using namespace std;

// 贪心算法
// 观察得之
// [1, 2, ] 添加3，即可以得到[1 ... 6]
// 

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    	long long top = 0; // 当前能到达的连续最大值 [1 ... top]
    	int patch = 0;
    	int i = 0;

    	while (top < n) {
    		if (i >= (int)nums.size() || top + 1 < nums[i]) {
    			++patch;
    			top += (top + 1);
    		} else {
    			top += nums[i];
    			++i;
    		}
    	}

    	return patch;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1, 2, 4};
	cout << solution.minPatches(nums, 8) << endl;
	return 0;
}