// 偷懒
// 用了 set
// 和 优先队列

// 算了, 还是不偷懒了
// 写个精细一点的

// 边界条件有点恶心
// 直接用了 LLI

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int maxNum = LLONG_MIN;
        long long int midNum = LLONG_MIN;
        long long int smallNum = LLONG_MIN;

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] > maxNum) {
                smallNum = midNum;
                midNum = maxNum;
                maxNum = nums[i];
            } else if (nums[i] < maxNum && nums[i] > midNum) {
                smallNum = midNum;
                midNum = nums[i];
            } else if (nums[i] < midNum && nums[i] > smallNum) {
                smallNum = nums[i];
            }
        }

        return smallNum != LLONG_MIN ? smallNum : maxNum;
    }
};