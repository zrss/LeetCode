// 偷懒
// 用了 set
// 和 优先队列

// 算了, 还是不偷懒了
// 写个精细一点的

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int maxNum = INT_MIN;
        int midNum = INT_MIN;
        int smallNum = INT_MIN;

        int cnt = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] > maxNum) {
                smallNum = midNum;
                midNum = maxNum;
                maxNum = nums[i];
                ++cnt;
            } else if (nums[i] != maxNum && nums[i] > midNum) {
                smallNum = midNum;
                midNum = nums[i];
                ++cnt;
            } else if (nums[i] != midNum && nums[i] > smallNum) {
                smallNum = nums[i];
                ++cnt;
            }
        }

        if (cnt >= 3)
            return smallNum;
        return maxNum;
    }
};