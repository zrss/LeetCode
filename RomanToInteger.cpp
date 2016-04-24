#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 加法游戏

class Solution {
public:
    int romanToInt(string s) {
    	unordered_map<char, int> map = {
    		{'I', 1},
    		{'V', 5},
    		{'X', 10},
    		{'L', 50},
    		{'C', 100},
    		{'D', 500},
    		{'M', 1000}
    	};

    	int value = 0;

    	for (int i = 0; i < s.length(); ++i) {    		
    		// I X C
    		if (i + 1 != s.length()) {
	    		switch (s[i]) {
	    			case 'I':
	    				if (s[i + 1] == 'V' || s[i + 1] == 'X') {
	    					value += (s[i + 1] == 'V' ? 4 : 9);
		    				++i;
	    					continue;
	    				}
	    			break;
	    			case 'X':
	    				if (s[i + 1] == 'L' || s[i + 1] == 'C') {
	    					value += (s[i + 1] == 'L' ? 40 : 90);
		    				++i;
	    					continue;
	    				}
	    			break;
	    			case 'C':
	    				if (s[i + 1] == 'D' || s[i + 1] == 'M') {
	    					value += (s[i + 1] == 'D' ? 400 : 900);
		    				++i;
	    					continue;
	    				}
    				break;
	    		}
    		}

    		// Other
    		value += (map.find(s[i])->second);
    	}

    	return value;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.romanToInt("MCMXC") << endl;
	return 0;
}
