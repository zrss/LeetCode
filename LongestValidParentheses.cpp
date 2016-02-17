#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<int> stack;
    	vector<bool> match;

    	int i = 0;
    	while (i < s.length()) {
    		if (s[i] == '(') {
    			match.push_back(false);
    			stack.push(match.size() - 1);
    		} else {
    			if (!stack.empty()) {
    				int index = stack.top();
    				match[index] = true;
    				stack.pop();
    			} else {
    				match.push_back(false);
    			}
    		}
    		++i;
    	}

    	// 扫描连续的匹配括号
    	int maxLen = 0;
    	int len = 0;
    	i = 0;

    	while (i < match.size()) {
    		if (match[i]) {
    			while (i < match.size() && match[i++]) {
	    			len += 2;
	    		}
	    		if (len > maxLen) {
	    			maxLen = len;
	    		}
	    		len ^= len;
    		} else {
    			++i;
    		}
    	}

    	return maxLen;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.longestValidParentheses("(((((") << endl;
	return 0;
}