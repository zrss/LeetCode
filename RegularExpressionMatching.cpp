#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	if (p.empty()) {
    		return s.empty();
    	}

    	if (p[1] == '*') {
    		return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p)));
    	} else {
    		return (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.isMatch("abc", "a*abc") << endl;
	return 0;
}