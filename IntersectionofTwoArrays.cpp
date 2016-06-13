#include <vector>
#include <unordered_set>

using namespace std;

/*

	set manipulation
	may be there is a elegant method to solve it

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	unordered_set<int> uniqueNum1;
    	for (int num : nums1) {
    		uniqueNum1.insert(num);
    	}

    	unordered_set<int> uniqueResult;
    	for (int num : nums2) {
    		if (uniqueNum1.find(num) != uniqueNum1.end()) {
    			uniqueResult.insert(num);    			
    		}
    	}

    	vector<int> result;
    	for (int num : uniqueResult) {
    		result.push_back(num);
    	}

    	return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}