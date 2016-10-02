#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cctype>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

typedef unsigned long long int		ULLN;
typedef long long int         		LLN;
typedef vector<int>                 VI;
typedef vector<vector<int> >        VVI;
typedef vector<string>              VS;
typedef vector<vector<string> >     VVS;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if (num > 10)
        	num = 10;

        vector<string> result;
        lightLed(num, 0, 0, 0, result);
        return result;
    }

    void lightLed(int ledNum, int position, int hours, int minutes, vector<string>& result) {
    	if (ledNum == 0) {
    		stringstream ss;
    		ss << hours << ":";
    		if (minutes <= 9) {
    			ss << "0";
    		}
    		ss << minutes;

    		result.push_back(ss.str());
    		return;
    	}

    	if ((10 - position) < ledNum) {
    		return;
    	}

    	// position on
    	if (position < 4) { // hours
			int value = 1 << (3 - position);
			hours += value;
			if (hours <= 11) {
				lightLed(ledNum - 1, position + 1, hours, minutes, result);
			}
			hours -= value;
		} else { // minutes
			int value = 1 << (9 - position);
			minutes += value;
			if (minutes <= 59) {
				lightLed(ledNum - 1, position + 1, hours, minutes, result);
			}
			minutes -= value;
		}

		// position off
    	lightLed(ledNum, position + 1, hours, minutes, result);
    }
};

int main() {
	return 0;
}