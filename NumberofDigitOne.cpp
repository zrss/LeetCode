#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int rel = 0;
        for (int i = 1; i <= n; ++i) {
        	int tmp = i;
        	while (tmp) {
        		if ((tmp % 10) == 1) {
        			++rel;
        		}
        		tmp /= 10;
        	}
        }
        return rel;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.countDigitOne(13) << endl;
	return 0;
}