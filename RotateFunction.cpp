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

// deque solution
// t O(n)
// s O(n)

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
    	if (A.size() <= 1) {
    		return 0;
    	}

    	int len = A.size();
    	int maxSum = INT_MIN;

    	int cnt = A.size();
    	int t = 0;

    	deque<int> dq;
    	int totalSum = 0;
    	int sum = 0;
    	for (int i = 0; i < len; ++i) {
    		totalSum += A[i];
    		dq.push_back(A[i]);
    		sum += i * A[i];
    	}

    	maxSum = max(maxSum, sum);
    	--cnt;

    	while (t < cnt) {
    		int remainNum = dq.front();

    		sum += (totalSum - dq.front());
    		sum -= (dq.back() * len);
    		sum += remainNum;

    		maxSum = max(maxSum, sum);

    		dq.push_front(dq.back());
    		dq.pop_back();
	        ++t;
    	}

    	return maxSum;
    }
};

int main() {
	VI A = {4, 3, 2, 6};
	cout << Solution().maxRotateFunction(A) << endl;
	return 0;
}