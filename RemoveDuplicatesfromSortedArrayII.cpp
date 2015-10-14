#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto itr = nums.begin(); itr != nums.end(); ) {
        	auto rel = map.find(*itr);
        	if (rel != map.end()) {
        		if (rel->second == 2) {
        			itr = nums.erase(itr);
        		} else {
        			++(rel->second);
        			++itr;
        		}
        	} else {
        		map.insert(pair<int, int>(*itr, 1));
        		++itr;
        	}
        }

    	return nums.size();
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;

	return 0;
}