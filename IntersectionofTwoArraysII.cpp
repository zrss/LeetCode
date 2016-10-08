#include <vector>
#include <unordered_map>

using namespace std;

// 哈希表 
// T: M + N
// S: M

// 排序 + 双指针 
// T: MlogM + NlogN 
// S: 1

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	unordered_map<int, int> nums1Map;
    	for (int num : nums1) {
    		++nums1Map[num];
    	}

    	vector<int> result;
    	for (int num : nums2) {
    		auto itr = nums1Map.find(num);
    		if (itr != nums1Map.end()) {
    			result.push_back(num);
    			--(itr->second);
    			if (itr->second == 0) {
    				nums1Map.erase(itr);
    			}
    		}
    	}

    	return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}