#include <string>
#include <unordered_set>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
    	int llen = 0;
    	int start = 0;
    	int end = 0;

    	std::unordered_set<char> hashTable;
    	
    	while (true) {
	    	while (end < s.length() && hashTable.find(s[end]) == hashTable.end()) {
	    		hashTable.insert(s[end]);
	    		++end;
	    	}

	    	if (end - start > llen) {
	    		llen = end - start;
	    	}

	    	if (end == s.length()) {
	    		break;
	    	}

	    	for (int i = start; i < end; ++i) {
	    		if (s[i] == s[end]) {
	    			start = i + 1;
	    			break;
	    		}
	    		hashTable.erase(s[i]);
	    	}

	    	hashTable.insert(s[end]);
	    	++end;
    	}

    	return llen;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	std::string test("aaabc");
	std::cout << solution.lengthOfLongestSubstring(test) << std::endl;
	return 0;
}