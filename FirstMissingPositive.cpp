#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int cnt = nums.size();

        for (int i = 0; i < cnt; ++i) {
        	if (nums[i] == i + 1) {
        		continue;
        	}
        	int x = nums[i];
        	while (x >= 1 && x <= cnt && x != nums[x - 1]) { // x should be in num[x - 1]
        		swap(x, nums[x - 1]);
        	}
        }

        for (int i = 0; i < cnt; ++i) {
        	if (i + 1 != nums[i]) {
        		return i + 1;
        	}
        }

        return cnt + 1;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}