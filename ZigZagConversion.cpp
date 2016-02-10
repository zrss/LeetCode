#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	// ps!: numRows 大于实际上的行数
    	if (numRows <= 1) {
    		return s;
    	}

    	int gap = (numRows - 2) + numRows;
    	string rel;

    	vector<vector<int>> flag(numRows, vector<int>());
    	flag[0].push_back(0);

    	for (int i = 1; i < numRows - 1; ++i) {
    		flag[i].push_back(i);
    		flag[i].push_back(gap - i);
    	}

    	flag[numRows - 1].push_back(numRows - 1);

    	for (int i = 0; i < numRows; ++i) {
    		for (auto itr : flag[i]) {
    			if (itr < s.length()) {
					rel += s[itr];
    			} else {
    				break;
    			}
    		}

    		int cur = 0;
    		int tmpGap = gap;
    		while (cur < s.length()) {
	    		for (auto itr : flag[i]) {
	    			cur = itr + tmpGap;
	    			if (cur < s.length()) {
	    				rel += s[cur];
	    			}
	    		}
	    		tmpGap += gap;
    		}
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.convert("A", 2) << endl;
	return 0;
}