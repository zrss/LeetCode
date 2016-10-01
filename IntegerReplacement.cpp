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

// tricky solution

class Solution {
public:
    int integerReplacement(int n) {
		if (n == INT_MAX) { // special case
			return 32;
		}

    	int cnt = 0;

    	while (n != 1) {
    		if (n & 1) {
    			// special case
    			if (n == 3) {
    				cnt += 2;
    				return cnt;
    			}

	        	// [1] = 1 +
	        	// [1] = 0 -
	        	if (0x02 & n) {
	        		++n;
	        	} else {
	        		--n;
	        	}

	        	++cnt;
	        } else {
	        	n >>= 1;
	        	++cnt;
	        }
    	}
        
        return cnt;
    }
};

int main() {
	cout << Solution().integerReplacement(65535) << endl;
	return 0;
}