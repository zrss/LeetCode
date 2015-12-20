#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	sort(strs.begin(), strs.end());

    	unordered_map<string, int> map;
    	int count[26];

    	vector<vector<string>> rel;

    	for (string cur : strs) {
    		memset(count, 0, sizeof(count));
    		for (int i = 0; i < cur.length(); ++i) {
    			++count[cur[i] - 'a'];
    		}

    		stringstream ss;
    		for (int i = 0; i < 26; ++i) {
    			ss << count[i];
    		}
    		string tmp = ss.str();

    		auto itr = map.find(tmp);
    		if (itr != map.end()) {
    			rel[itr->second].push_back(cur);
    		} else {
    			vector<string> init = {cur};
    			rel.push_back(init);
    			map.insert(pair<string, int>(tmp, rel.size() - 1));
    		}
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	auto rel = solution.groupAnagrams(strs);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto next = itr->begin(); next != itr->end(); ++next) {
			cout << *next << " ";
		}
		cout << endl;
	}
	return 0;
}