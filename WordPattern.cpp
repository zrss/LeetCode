#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	string cpy = pattern;
        vector<vector<int>> index;
        for (int i = 0; i < cpy.length(); ++i) {
        	if (cpy[i] != ' ') {
	        	vector<int> tmp;
	        	for (int j = i; j < cpy.length(); ++j) {
	        		if (pattern[i] == cpy[j]) {
		        		tmp.push_back(j);
		        		cpy[j] = ' ';
	        		}
	        	}
	        	index.push_back(tmp);
        	}
        }

        vector<string> text;
        int start = 0;
        for (int i = 0; i < str.length(); ++i) {
        	if (str[i] == ' ' && start != i) {
    			text.push_back(str.substr(start, i - start));
    			start = i + 1;
        	}
        }
		text.push_back(str.substr(start, str.length()));

		unordered_map<string, int> map;
		for (string cur : text) {
			auto itr = map.find(cur);
			if (itr != map.end()) {
				++(itr->second);
			} else {
				map.insert(pair<string, int>(cur, 1));
			}
		}

		if (index.size() != map.size()) {
			return false;
		}

		for (int i = 0; i < index.size(); ++i) {
			auto itr = map.find(text[index[i][0]]);

			if (itr->second != index[i].size()) {
				return false;
			}

			for (int j = 1; j < index[i].size(); ++j) {
				if (!(text[index[i][j]] == text[index[i][j - 1]])) {
					return false;
				}
			}
		}

		return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	solution.wordPattern("abccccc", "boy cat");
	return 0;
}