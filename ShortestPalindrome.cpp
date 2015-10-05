#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
    	string rev(s);
    	reverse(rev.begin(), rev.end());

    	int len = s.length();

    	for (int i = len; i > 0; --i) {
    		if (s.substr(0, i) == rev.substr(len - i))
    			return rev.substr(0, len - i) + s;
    	}

    	return s; // ""
    }
};