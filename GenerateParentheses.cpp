#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> rel;
    	helper(rel, "", n, n);
    	return rel;
    }

    void helper(vector<string>& rel, string paren, int left, int right) {
    	if (left == 0 && right == 0) {
    		rel.push_back(paren);
    		return;
    	}

    	if (left > 0)
    		helper(rel, paren + '(', left - 1, right);

    	if (right > 0 && right > left)
    		helper(rel, paren + ')', left, right - 1);
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<string> rel = solution.generateParenthesis(4);
	for (auto str : rel) {
		cout << str << endl;
	}
	return 0;
}