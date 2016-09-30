#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int posS = 0;
		int posT = 0;

		int lenS = s.length();
		int lenT = t.length();

		bool cont = true;
		while (cont && posS < lenS) {
			bool found = false;
			while (!found && posT < lenT) {
				if (s[posS] == t[posT]) {
					found = true;
				}
				++posT;
			}
			if (!found) {
				cont = false;
			}
			++posS;
		}

		return cont;
	}
};

int main(int argc, char const *argv[]) {
	cout << Solution().isSubsequence("axc", "ahbgdc") << endl;
	return 0;
}