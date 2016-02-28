#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
    	vector<int> cnt(26, 0);

    	for (auto ch : s) {
    		++cnt[ch - 'a'];
    	}

    	stack<char> stack;
    	vector<bool> added(26, false);

    	for (auto ch : s) {

    		--cnt[ch - 'a'];

    		if (added[ch - 'a']) {
    			continue;
    		}

    		// 贪心
    		while (!stack.empty() && stack.top() > ch && cnt[stack.top() - 'a'] > 0) {
    			added[stack.top() - 'a'] = false;
    			stack.pop();
    		}

    		added[ch - 'a'] = true;
    		stack.push(ch);
    	}

    	string rel;
    	while (!stack.empty()) {
    		rel += stack.top();
    		stack.pop();
    	}

    	reverse(rel.begin(), rel.end());
    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.removeDuplicateLetters("bcabc") << endl;
	return 0;
}