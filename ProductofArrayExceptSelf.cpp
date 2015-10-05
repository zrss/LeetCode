#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	vector<int> rel;

    	if (nums.size() == 0) {
    		return rel;
    	}

    	vector<int> f(nums.size(), 0);
    	vector<int> b(nums.size(), 0);

    	f[0] = nums[0];
    	for (int i = 1; i < nums.size(); ++i) {
    		f[i] = nums[i] * f[i - 1];
    	}

    	b[nums.size() - 1] = nums[nums.size() - 1];
    	for (int i = nums.size() - 2; i >= 0; --i) {
    		b[i] = nums[i] * b[i + 1];
    	}

    	for (int i = 0; i < nums.size(); ++i) {
    		if (i != 0 && i != nums.size() - 1) {
    			rel.push_back(f[i - 1] * b[i + 1]);
    		} else if (i == 0) {
                rel.push_back(b[i + 1]);
            } else {
                rel.push_back(f[i - 1]);
            }
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