#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        if (n == 0 || !notZero(s[0])) // error case
        	return 0;

        int rel = 1;
        int d_n_1 = 1;
        int d_n_2 = 1;

        for (int i = 1; i < n; ++i) {
        	bool sing = notZero(s[i]);
        	bool comb = inRange(s[i - 1], s[i]);

        	if (sing && comb) {
        		rel = d_n_1 + d_n_2;
        	} else if (!sing && comb) {
        		rel = d_n_2;
        	} else if (sing && !comb) {
        		rel = d_n_1;
        	} else {
        		return 0; // error case
        	}

        	d_n_2 = d_n_1;
        	d_n_1 = rel;
        }

        return rel;
    }

    bool inRange(char a, char b) {
    	return a == '1' || (a == '2' && b <= '6');
    }

    bool notZero(char a) {
    	return a != '0';
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;

	cout << solution.numDecodings("1") << endl;
	return 0;
}