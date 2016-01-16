#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	string rel;

        num1 = strim(num1);
        num2 = strim(num2);

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

    	for (int i = num2.length() - 1; i >= 0; --i) {
    		string step = singleMultiply(num1, num2[i]);
    		for (int c = 0; c < num2.length() - i - 1; ++c) {
    			step.push_back('0');
    		}
    		rel = addString(step, rel);
    	}

    	return rel;
    }

    string strim(string& num) {
        string rel;
        int i = 0;
        while (num[i] == '0') {
            ++i;
        }
        if (i == num.length()) {
            return "0";
        }
        return num.substr(i, string::npos);
    }

    string singleMultiply(string& num, char& ch) {
    	string rel;

    	if (num.length() <= 0 || !(ch >= '0' && ch <= '9')) {
    		return rel;
    	}

    	int B = ch - '0';
    	int in = 0;
    	for (int i = num.length() - 1; i >= 0; --i) {
    		int A = num[i] - '0';
    		int t = A * B + in;
    		in = t / 10;
    		rel.push_back(t % 10 + '0');
    	}

    	if (in > 0) {
    		rel.push_back(in + '0');
    	}

    	reverse(rel.begin(), rel.end());

        return rel;
    }

    string addString(string& num1, string& num2) {
    	int len = min(num1.length(), num2.length());

    	int n1 = num1.length() - 1;
    	int n2 = num2.length() - 1;

    	int in = 0;

    	string rel;

    	for (int c = 0; c < len; ++c) {
    		int A = num1[n1--] - '0';
    		int B = num2[n2--] - '0';

    		int t = A + B + in;

    		rel.push_back(t % 10 + '0');
    		in = t / 10;
    	}

    	if (n1 >= 0) {
    		for (int i = n1; i >= 0; --i) {
    			int t = num1[i] - '0' + in;
    			rel.push_back(t % 10 + '0');
                in = t / 10;
    		}
    	} else {
    		for (int i = n2; i >= 0; --i) {
    			int t = num2[i] - '0' + in;
    			rel.push_back(t % 10 + '0');
                in = t / 10;
    		}
    	}

    	if (in > 0) {
    		rel.push_back(in + '0');
    	}

    	reverse(rel.begin(), rel.end());

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.multiply("00000000", "23") << endl;
	return 0;
}