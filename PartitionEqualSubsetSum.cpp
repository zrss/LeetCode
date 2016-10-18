class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
        }

        // 奇数当然就不能划分咯
        if ((sum & 1) != 0) {
            return false;
        }
        sum >>= 1;

        // 0-1 backpack
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        
        // 每个数字只能使用一次
        for (int i = 0; i < len; ++i) {
            // 从后往前避免重复使用
            for (int j = sum; j >= nums[i]; --j) {
                if (dp[j - nums[i]]) {
                    dp[j] = dp[j - nums[i]];
                }
            }
        }

        return dp[sum];
    }
};