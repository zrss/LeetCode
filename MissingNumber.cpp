#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

// 数字范围[0 ... n]
// 找出中间缺失的一个数

// 方法1
// 1 - n 加和
// 减掉当前数组的和
// 时间复杂度 O(n)
// 空间复杂度 O(1)
// 有可能溢出

// 方法2
// 存在映射 0 -> 0, 1 -> 1, 2 -> 2
// 所以每次将nums[i] 交换至 nums[nums[i]] 即可

// 方法3
// bitmap
// 空间复杂度不符合要求
// O (n / 8 / 4)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int n = nums.size();

    	int total = n * (n + 1) >> 1;
    	int cur = 0;

    	for (int i = 0; i < n; ++i) {
    		cur += nums[i];
    	}

    	return total - cur;
    }

    int missingNumber2(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (i != nums[i] && nums[i] != len) { // 持续交换到对应的位置上, nums[index] = index
                swap(nums[i], nums[nums[i]]); 
            }
        }

        // 交换结束之后，因为仅有一个不匹配元素，所以其对应的下标即是缺失的元素
        for (int i = 0; i < len; ++i) {
            if (i != nums[i]) {
                return i;
            }
        }

        return len;
    }

    int missingNumber3(vector<int>& nums) {
        bitset<100000> bitset;
        for (int i = 0; i < nums.size(); ++i) {
            bitset.set(nums[i]);
        }
        for (int i = 0; i < 100000; ++i) {
            if (bitset.test(i) == false) {
                return i;
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
	vector<int> nums = {0, 1, 3};
	Solution solution;
	cout << solution.missingNumber3(nums) << endl;
	return 0;
}