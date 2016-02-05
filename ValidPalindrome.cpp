#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	string target;

    	for (int i = 0; i < s.length(); ++i) {
    		if (validChar(s[i])) {
    			if (s[i] >= 'A' && s[i] <= 'Z') {
    				target += (s[i] + 32);
    			} else {
    				target += s[i];
    			}
    		}
    	}

    	int start = 0;
    	int end = target.length() - 1;

    	while (start < end) {
    		if (target[start] != target[end]) {
    			return false;
    		}
    		++start;
    		--end;
    	}

    	return true;
    }

    bool validChar(char c) {
    	if (c >= '0' && c <= '9') {
    		return true;
    	}

    	if (c >= 'a' && c <= 'z') {
    		return true;
    	}

    	if (c >= 'A' && c <= 'Z') {
    		return true;
    	}

    	return false;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.isPalindrome("race a car") << endl;
	return 0;
}