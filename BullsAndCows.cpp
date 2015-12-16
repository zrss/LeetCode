#include <iostream>
#include <string>
#include <cstring>
#include <sstream>  

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
    	int count[10];

    	memset(count, 0, sizeof(count));

    	int bulls = 0;
    	int cows = 0;

    	// 
    	for (int i = 0; i < secret.length(); ++i) {
    		++count[secret[i] - '0'];
    	}

    	//
    	for (int i = 0; i < secret.length(); ++i) {
			int num = guess[i] - '0';

    		if (secret[i] == guess[i]) {
    			--count[num];
    			++bulls;
    		}
    	}

    	// 
    	for (int i = 0; i < secret.length(); ++i) {
			int num = guess[i] - '0';

			if (secret[i] != guess[i] && count[num] > 0) {
				++cows;
				--count[num];
			}
    	}


    	stringstream ss;
    	ss << bulls << "A" << cows << "B";

    	return ss.str();
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.getHint("1123", "0111") << endl;
	return 0;
}