#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto itr = nums.begin(); itr != nums.end(); ) {
        	if (*itr == val) {
        		itr = nums.erase(itr);
        	} else {
        		++itr;
        	}
        }

        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	vector<int> nums = {1,2,3,4};
	cout << solution.removeElement(nums, 2) << endl;
	return 0;
}