#include <iostream>
#include <string>

using namespace std;

// 天了噜
// 想了一会儿完全木有思路
//
// 只能参考大神的思路来理解咯
// 好吧一般来说迭代的是人，递归的是神-_-

class Solution {
public:
    bool isMatch(string s, string p) {
    	if (p.empty()) {
    		return s.empty();
    	}

    	if (p[1] == '*') {
    		return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p)));
    	} else {
    		return (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.isMatch("abc", "a*abc") << endl;
	return 0;
}