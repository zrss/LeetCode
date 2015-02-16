#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
    	// there is a trap when s is a single char
    	if (s.length() <= 1) {
    		return s;
    	}

    	std::string lP;
    	int maxCount = 0;

        // odd length
        for (int i = 1; i < s.length(); ++i) {
        	int count = 1;
        	int left = i - 1;
        	int right = i + 1;

        	while (left >= 0 && right < s.length() && (s[left] == s[right])) {
        		count += 2;
        		--left;
        		++right;
        	}

        	if (count > maxCount) {
        		maxCount = count;
        		lP = s.substr(left + 1, count);
        	}
        }
 
        // even length
        for (int i = 0; i < s.length(); ++i) {
        	int count = 0;
        	int left = i;
        	int right = i + 1;

        	while (left >= 0 && right < s.length() && (s[left] == s[right])) {
        		count += 2;
        		--left;
        		++right;
        	}

        	if (count > maxCount) {
        		maxCount = count;
        		lP = s.substr(left + 1, count);
        	}
        }

        return lP;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	std::string test("jkljljljjjlj");
	std::cout << solution.longestPalindrome(test) << std::endl;
	return 0;
}