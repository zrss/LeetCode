#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.length() != t.length())
    		return false;

        int sC[26]{};
        int tC[26]{};

        for (int i = 0; i < s.length(); ++i) {
        	++sC[s[i] - 'a'];
        }

        for (int i = 0; i < t.length(); ++i) {
        	++tC[t[i] - 'a'];
        }

        bool rel = true;

        for (int i = 0; rel && i < 26; ++i) {
        	if (sC[i] != tC[i]) {
        		rel = false;
        	}
        }

        return rel;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.isAnagram("anagram", "nagaram") << endl;
	return 0;
}