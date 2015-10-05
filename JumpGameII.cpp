#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
        int size = nums.size();
        int i = 0, step = 0;
        int curStepReach = nums[0]; //furthest idex the current step can reach
        int nextStepReach = 0; //furthest idex the next step can reach
        while (curStepReach < size-1) //the loop stops when the next step can reach the end index
        {
            for (; i <= curStepReach; i++) //for each index of the current step
                nextStepReach = max(nextStepReach, nums[i]+i); //update the most furthest idex

            curStepReach = nextStepReach;
            step++; //the step increases
        }

        return size == 1 ? 0 : ++step; //we don't need jump when the size is 1
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> nums = {1,2,1,1,4,1,1,1};
	cout << solution.jump(nums) << endl;
	return 0;
}