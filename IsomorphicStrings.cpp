#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	unordered_map<char, char> map;
    	unordered_set<char> match;

    	for (int i = 0; i < s.length(); ++i) {
    		auto itr = map.find(s[i]);
    		if (itr != map.end()) {
    			if (itr->second != t[i]) {
    				return false;
    			}
    		} else {
    			if (match.count(t[i]) > 0) {
    				return false;
    			}
    			map.insert(pair<char, char>(s[i], t[i]));
    			match.insert(t[i]);
    		}
    	}
    	return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	string s = "ab";
	string t = "aa";
	cout << solution.isIsomorphic(s, t) << endl;
	return 0;
}