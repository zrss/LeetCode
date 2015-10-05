#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len = a.length() < b.length() ? b.length() : a.length();
        int* aArray = new int[len];
        int* bArray = new int[len];

        memset(aArray, 0, sizeof(int) * len);
        memset(bArray, 0, sizeof(int) * len);

        // convert
        for (int i = a.length() - 1, c = 0; i >= 0; --i) {
        	aArray[c++] = a[i] - '0';
        }
        for (int i = b.length() - 1, c = 0; i >= 0; --i) {
        	bArray[c++] = b[i] - '0';
        }

        int* rel = new int[len + 1];
        memset(rel, 0, sizeof(int) * (len + 1));

        // add
        for (int i = 0; i < len; ++i) {
        	rel[i] += (aArray[i] + bArray[i]);
        	rel[i + 1] += (rel[i] / 2);
        	rel[i] %= 2;
        }

        // convert
        string str;

        // trim
        int start = len;
        while (rel[start] == 0 && start > 0) {
        	--start;
        }

        for (; start >= 0; --start) {
        	str.push_back(rel[start] + '0');
        }

        return str;

        delete [] aArray;
        delete [] bArray;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.addBinary("00000", "000000000") << endl;
	return 0;
}