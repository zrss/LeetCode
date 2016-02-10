#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0) {
    		return "";
    	}

    	// 有无空字符串
    	for (auto itr : strs) {
    		if (itr.length() == 0) {
    			return "";
    		}
    	}

    	// 匹配
    	int cur = 0;
    	char ch;

    	while (cur < strs[0].length()) {
			ch = strs[0][cur];
    		for (int i = 1; i < strs.size(); ++i) {
    			if (cur < strs[i].length()) {
    				if (strs[i][cur] != ch) {
    					return strs[i].substr(0, cur);
    				}
    			} else {
    				return strs[i];
    			}
    		}
    		++cur;
    	}

    	return strs[0];
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<string> strs = {"A", "B"};
	cout << solution.longestCommonPrefix(strs) << endl;
	return 0;
}