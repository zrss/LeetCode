#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> rel;

        int n = nums.size();
        if (!n) {
        	return rel;
        }

        int start = nums[0];

        for (int i = 1; i < n; ++i) {
        	if (nums[i] != nums[i - 1] + 1) {
        		stringstream ss;

        		if (start != nums[i - 1]) {
        			ss << start << "->" << nums[i - 1];
        		} else {
        			ss << start;
        		}

        		rel.push_back(ss.str());
        		start = nums[i];
        	}
        }

        stringstream ss;

		if (start != nums[n - 1]) {
			ss << start << "->" << nums[n - 1];
		} else {
			ss << start;
		}

		rel.push_back(ss.str());

		return rel;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	vector<int> nums = {1, 3};
	vector<string> rel = solution.summaryRanges(nums);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		cout << *itr << endl;
	}
	return 0;
}