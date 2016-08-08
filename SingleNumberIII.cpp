#include <iostream>
#include <vector>

using namespace std;

// 趣味题
// 位操作

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int i = 0; i < nums.size(); ++i) {
        	diff ^= nums[i];
        }
        
        // diff 表示两个不同数的异或结果
        // 扫描第一个1的位置
        int flag = 1;
        while (!(flag & diff)) {
        	flag <<= 1;
        }

        // 1的位置即表示不相同的两数，在这个二进制位上不同
        // 因此通过该位分组
        // 分别异或即可得到原数
        vector<int> rel = {0, 0};
        for (int i = 0; i < nums.size(); ++i) {
        	if (nums[i] & flag) {
        		rel[0] ^= nums[i];
        	} else {
        		rel[1] ^= nums[i];
        	}
        }

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1,1,2,3};
	vector<int> rel = solution.singleNumber(nums);
	cout << rel[0] << " " << rel[1] << endl;
	return 0;
}