#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> d(nums.size(), 0);
        vector<int> n(nums.size(), 0);

        int max = nums[0];
        d[0] = nums[0];
        n[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int v1 = d[i - 1] * nums[i];
            int v2 = n[i - 1] * nums[i];
            int v3 = nums[i];

            if (v1 < v2) {
                swap(v1, v2);
            }
            if (v1 < v3) {
                swap(v1, v3);
            }
            if (v2 < v3) {
                swap(v2, v3);
            }

            d[i] = v1;
            n[i] = v3;

            if (d[i] > max) {
                max = d[i];
            }
        }

        return max;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> nums = {-1, -1, -2, 4};
    cout << solution.maxProduct(nums) << endl;
    return 0;
}