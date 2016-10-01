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
    int maxRotateFunction(vector<int>& A) {
    	if (A.size() <= 1) {
    		return 0;
    	}

    	int len = A.size();

    	int totalSum = 0;
    	int sum = 0;
    	for (int i = 0; i < len; ++i) {
    		totalSum += A[i];
    		sum += i * A[i];
    	}

    	int maxSum = sum;

   		for (int i = len - 2; i >= 0; --i) {
    		sum += (totalSum - A[i + 1]);
    		sum -= (A[i + 1] * (len - 1));
    		maxSum = max(maxSum, sum);
    	}

    	return maxSum;
    }
};

int main() {
	VI A = {4, 3, 2, 6};
	cout << Solution().maxRotateFunction(A) << endl;
	return 0;
}