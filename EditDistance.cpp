#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// 经典动态规划问题

// d[i][j]
// denote
// word1[0...i], word2[0...j] min edit distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> d(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 1; i <= word1.length(); ++i) {
        	d[i][0] = i;
        }
        for (int i = 1; i <= word2.length(); ++i) {
        	d[0][i] = i;
        }
        for (int i = 1; i <= word1.length(); ++i) {
        	for (int j = 1; j <= word2.length(); ++j) {
        		d[i][j] = min(d[i - 1][j], d[i][j - 1]);
        		++d[i][j];

        		if (word1[i - 1] == word2[j - 1]) {
        			d[i][j] = min(d[i][j], d[i - 1][j - 1]);
        		} else {
        			d[i][j] = min(d[i][j], d[i - 1][j - 1] + 1);
        		}
        	}
        }
        if (word1.length() == 0) {
        	return word2.length();
        } 
        if (word2.length() == 0) {
        	return word1.length();
        }
        return d[word1.length()][word2.length()];
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.minDistance("ab", "bc") << endl;
    return 0;
}