/* hash */

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	if (nums.size() == 0)
    		return 0;

    	int maxLen = 1;
    	unordered_set<int> set(nums.begin(), nums.end());

    	while (!set.empty()) {
    		int len = 1;
    		unordered_set<int>::iterator first = set.begin();
    		unordered_set<int>::iterator itr = first;

    		int cur = *first;
    		set.erase(first);

    		while ((itr = set.find(cur + 1)) != set.end()) {
    			++len;
    			cur = *itr;
    			set.erase(itr);
    		}

    		cur = *first;

    		while ((itr = set.find(cur - 1)) != set.end()) {
    			++len;
    			cur = *itr;
    			set.erase(itr);
    		}

    		if (len > maxLen) {
    			maxLen = len;
    		}
    	}

    	return maxLen;
    }
};