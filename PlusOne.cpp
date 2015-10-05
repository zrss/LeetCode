#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int in = 1;

    	digits.insert(digits.begin(), 0);

        for (int l = digits.size() - 1; in != 0 && l >= 0; --l) {
        	digits[l] += in;
        	in = digits[l] / 10;
        	digits[l] %= 10;
        }

        int s = 0;
        while (s < digits.size() && digits[s] == 0) {
        	++s;
        }

        digits.erase(digits.begin(), digits.begin() + s);

        return digits;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> digits = {};
	vector<int> rel = solution.plusOne(digits);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		cout << *itr;
	}
	cout << endl;
	return 0;
}