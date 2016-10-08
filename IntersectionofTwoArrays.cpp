#include <vector>
#include <unordered_set>

using namespace std;

// 直接用set，匹配过的删除

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	unordered_set<int> uniqueNum1;
    	for (int num : nums1) {
    		uniqueNum1.insert(num);
    	}

        vector<int> result;
    	for (int num : nums2) {
            auto itr = uniqueNum1.find(num);
    		if (itr != uniqueNum1.end()) {
    			result.push_back(num);
                uniqueNum1.erase(itr);
    		}
    	}

    	return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}