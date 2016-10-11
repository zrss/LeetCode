// trick problem

class Solution {
public:
    int longestPalindrome(string s) {
        int hash[256];
        memset(hash, 0, sizeof(hash));

        int len = s.length();
        for (int i = 0; i < len; ++i) {
        	++hash[s[i]];
        }

        int pLen = 0;
        for (int i = 0; i < 256; ++i) {
        	if ((hash[i] & 1) == 0) {
        		pLen += hash[i];
        	} else {
        	    if (hash[i] > 1) {
        	        pLen += (hash[i] - 1);
        	    }
        	}
        }

        if (pLen != len) {
        	++pLen;
        }

        return pLen;
    }
};