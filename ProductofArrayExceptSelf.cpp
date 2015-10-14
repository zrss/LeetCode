#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	vector<int> rel(nums.size(), 0);

        // left product i
        rel[0] = 1;
    	for (int i = 1; i < nums.size(); ++i) {
            rel[i] = nums[i - 1] * rel[i - 1];
        }

        // i right product
        int tmp = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            tmp *= nums[i + 1];
            rel[i] *= tmp;
        }

        return rel;
    }
};

int main() {
    vector<int> nums = {1,2};
    Solution solution;
    vector<int> rel = solution.productExceptSelf(nums);
    for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
	return 0;
}