// 位操作方法
// 很巧妙
// 左移与当前数字相同的位数，相当于之前的所有数字加上当前数字
// 当然 |= 保留当前数字

// 题目已经给出了限制
// 0 < nums[i] <= 100
// number of nums <= 200

// 所以 bitset 最大为 100 * 200 / 2 + 1 = 10001

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // 0位为 1
        bitset<10001> rel(1);
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            rel |= (rel << nums[i]);
        }

        return !(sum & 1) && bitset[sum >> 1];
    }
};