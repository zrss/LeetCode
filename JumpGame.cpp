#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
       if(nums.size() <= 1)return true;
       int step = nums[0];
       for(int i = 1; i < nums.size() - 1 && step != 0; i++){
           step--;
           step = max(step,nums[i]);//keep the step or change to the biggest step we can go now
       }
       return step != 0;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}