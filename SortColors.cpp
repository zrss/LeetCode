#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int oneCnt = 0;
        int s = 0;
        int e = nums.size() - 1;

        while () {
            if (nums[s] == 2 && nums[e] == 0) {
                swap(nums[s], nums[e]);
            } else {
                if (nums[s] == 1) {
                    ++oneCnt;
                    nums[s] = 0;
                }
                if (nums[e] == 1) {
                    ++oneCnt;
                    nums[e] = 2;
                }
            }
            ++s;
            --e;
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}