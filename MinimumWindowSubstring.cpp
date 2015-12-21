#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
    	int slen = s.length();
    	int tlen = t.length();

    	int dict[128] = {0};

    	fill(dict, dict + 128, -slen);

    	for (int i = 0; i < tlen; ++i) {
    		if (dict[t[i]] > 0) {
    			++dict[t[i]];
    		} else {
    			dict[t[i]] = 1;
    		}
    	}

    	int count = t.length();

    	int start = 0; // window start

    	int minWin = INT_MAX; // 
    	int minStart = 0; //

    	for (int end = 0; end < slen; ++end) {
    		// s[i] in t and window fit
    		if (--dict[s[end]] >= 0 && --count == 0) {
    			// if s[start] not in t or still have s[start] in window then move start
    			while (dict[s[start]] <= -slen || ++dict[s[start]] <= 0) {
    				++start;
    			}
    			// update minimum window length
    			if (end - start + 1 < minWin) {
    				minWin = end - start + 1;
    				minStart = start;
    			}
    			// continue to traverse
    			++start;
    			count = 1; // as moving forward start one step so only left 1 character unmatch
    		}
    	}

    	return minWin != INT_MAX ? s.substr(minStart, minWin) : "";
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	string s = "ADOBECODEBANC";
	string t = "ABC";

	cout << solution.minWindow(s, t) << endl;

	return 0;
}
