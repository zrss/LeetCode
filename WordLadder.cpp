#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	int maxlevel = 1;
    	queue<pair<string, int>> queue;
    	queue.push(pair<string, int>(beginWord, maxlevel));

    	wordList.insert(endWord);

    	while (!queue.empty()) {
    		pair<string, int> cur = queue.front();
    		queue.pop();

    		if (cur.second > maxlevel) {
    			maxlevel = cur.second;
    		}

    		if (cur.second == maxlevel - 2) {
    			break;
    		}

    	    // traverse dict
    	    for (auto itr = wordList.begin(); itr != wordList.end(); ) {
    	    	if (diffOne(*itr, cur.first)) {
    	    		if (*itr == endWord) {
    	    			return cur.second + 1;
    	    		}
    	    		queue.push(pair<string, int>(*itr, cur.second + 1));

    	    		itr = wordList.erase(itr);
    	    	} else {
    	    		++itr;
    	    	}
    	    }
    	}

    	return 0;
    }

    bool diffOne(const string& a, const string& b) {
    	if (a.length() != b.length()) { // problem definition
    		return false;
    	}

    	int diff = 0;
    	for (int i = 0; diff < 2 && i < a.length(); ++i) {
    		if (a[i] != b[i]) {
    			++diff;
    		}
    	}

    	return diff == 1;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log"};
	cout << solution.ladderLength("hit", "cog", wordList) << endl;
	return 0;
}