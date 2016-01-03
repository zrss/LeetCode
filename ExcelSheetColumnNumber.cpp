#include <iostream>

using namespace std;

// 26 进制
class Solution {
public:
    int titleToNumber(string s) {
    	int value = 0;
    	int map[26];
    	for (int i = 0; i < 26; ++i) {
    		map[i] = i + 1;
    	}

    	int times = 1;
    	for (int pos = s.length() - 1; pos >= 0; --pos) {
    		value += (map[s[pos] - 'A'] * times);
    		times *= 26;
    	}

    	return value;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.titleToNumber("AAA") << endl;
	return 0;
}