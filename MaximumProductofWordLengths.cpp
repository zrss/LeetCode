#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& s1, const string& s2) {
	return s1.length() > s2.length();
}

class Solution {
public:
    int maxProduct(vector<string>& words) {

    	sort(words.begin(), words.end(), cmp);

    	vector<int> cvt(words.size(), 0);

    	// 位操作
    	for (int i = 0; i < words.size(); ++i) {
    		for (int each = 0; each < words[i].length(); ++each) {
    			cvt[i] |= (1 << (words[i][each] - 'a'));
    		}
    	}

    	int endIndex = words.size();
    	int maxLen = 0;

    	for (int i = 0; i < endIndex; ++i) {
    		for (int j = i + 1; j < endIndex; ++j) {
    			int tmpLen = words[i].length() * words[j].length();
    			if (tmpLen > maxLen) {
    				// 没有公共部分
    				if ((cvt[i] & cvt[j]) == 0) {
    					maxLen = tmpLen;
    					endIndex = j;
    				}
    			} else {
    				break;
    			}
    		}
    	}

    	return maxLen;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	cout << solution.maxProduct(words) << endl;
	return 0;
}