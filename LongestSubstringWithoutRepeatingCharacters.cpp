#include <string>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
    	int llen = 0;
    	int start = 0;
    	int end = 0;

    	bool hashTable[256];
    	memset(hashTable, false, sizeof(hashTable));
    	
    	while (true) {
	    	while (end < s.length() && !hashTable[s[end]]) {
	    		hashTable[s[end]] = true;
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
	    		hashTable[s[i]] = true;
	    	}

	    	hashTable[s[end]] = true;
	    	++end;
    	}

    	return llen;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	std::string test("AAAAAaa");
	std::cout << solution.lengthOfLongestSubstring(test) << std::endl;
	return 0;
}