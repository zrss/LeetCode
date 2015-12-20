#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	int num = words.size(); // dict word number
    	int len = words[0].length(); // dict word len
    	int totalLen = s.length(); // s length

    	unordered_map<string, int> dict;

    	for (string str : words) {
    		++dict[str];
    	}

    	vector<int> rel;

    	for (int i = 0; i < totalLen - num * len - 1; ++i) {
    		unordered_map<string, int> count;
    		int j = 0;
    		for (; j < num; ++j) {
    			string str = s.substr(i + j * len, len);
    			if (dict.count(str) > 0) {
    				++count[str];
    				if (count[str] > dict[str]) {
    					break;
    				}
    			} else {
    				break;
    			}
    		}
    		if (j == num) {
    			rel.push_back(i);
    		}
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	string s = "barfoothefoobarman";
	vector<string> words = {"foo", "bar"};
	vector<int> rel = solution.findSubstring(s, words);
	for (int tmp : rel) {
		cout << tmp << " ";
	}
	cout << endl;
	return 0;
}