#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	if (digits.length() == 0) {
    		return vector<string>();
    	}
    	
    	vector<string> map = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    	int cur = 0;
    	string tmp;
    	vector<string> rel;

    	aux(digits, map, cur, tmp, rel);

    	return rel;
    }

    void aux(string& digits, vector<string>& map, int cur, string& tmp, vector<string>& rel) {
    	if (cur == digits.length()) {
    		rel.push_back(tmp);
    		return;
    	}

    	int index = digits[cur] - '0';
    	for (int i = 0; i < map[index].length(); ++i) {
    		tmp += map[index][i];
    		aux(digits, map, cur + 1, tmp, rel);
    		tmp.pop_back();
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<string> rel = solution.letterCombinations("");
	for (auto itr : rel) {
		cout << itr << endl;
	}
	return 0;
}