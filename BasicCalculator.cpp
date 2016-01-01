#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		int cur = 0;
		int num = 0;

		while (cur < s.length()) {
			num += formalCal(s, cur);
		}

		return num;
	}

	// calculate (...)
	int formalCal(string& s, int& cur) {
		int num = 0;

		while (cur < s.length()) {
			getNext(s, cur);
			if (cur == s.length()) {
				return num;
			}

			// (
			if (s[cur] == '(') {
				++cur;
				continue;
			}

			getNext(s, cur);
			if (cur == s.length()) {
				return num;
			}

			// num
			if (s[cur] >= '0' && s[cur] <= '9') {
				num = getNum(s, cur);
			}
			else {
				// operator
				if (s[cur] == '+') {
					num += getNum(s, ++cur);
				}
				else if (s[cur] == '-') {
					num -= getNum(s, ++cur);
				}
				else { // )
					++cur;
					return num;
				}
			}
		}

		return num;
	}

	void getNext(string& s, int& cur) {
		while (cur < s.length() && s[cur] == ' ') {
			++cur;
		}
	}

	int getNum(string& s, int& cur) {
		getNext(s, cur);

		int num = 0;

		if (cur < s.length() && s[cur] >= '0' && s[cur] <= '9') {
			while (cur < s.length() && s[cur] >= '0' && s[cur] <= '9') {
				num *= 10;
				num += (s[cur] - '0');
				++cur;
			}

			return num;
		}

		getNext(s, cur);

		if (cur < s.length() && s[cur] == '(') {
			return formalCal(s, cur);
		}
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.calculate("2-(5-6)") << endl;
	return 0;
}