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
	string decodeString(string s) {
		stack<int> count;
		stack<string> result;

		result.push("");
		int cur = 0;
		int len = s.length();
		while (cur < len) {
			if (s[cur] == '[') {
				result.push("");
			}
			else if (isdigit(s[cur])) {
				int cnt = 0;
				while (cur < len && isdigit(s[cur])) {
					cnt *= 10;
					cnt += (s[cur] - '0');
					++cur;
				}
				--cur;
				count.push(cnt);
			}
			else if (s[cur] == ']') {
				int rt = count.top();
				count.pop();
				string tmp = result.top();
				result.pop();

				string rstr;
				for (int i = 0; i < rt; ++i) {
					rstr += tmp;
				}

				tmp = result.top();
				result.pop();
				result.push(tmp + rstr);
			}
			else {
				string tmp = result.top();
				result.pop();
				result.push(tmp + s[cur]);
			}
			++cur;
		}

		return result.top();
	}
};

int main() {
	cout << Solution().decodeString("sd2[f2[e]g]i") << endl;
	return 0;
}