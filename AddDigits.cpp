#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
        	int tmp = 0;
        	while (num) {
        		tmp += (num % 10);
        		num /= 10;
        	}
        	num = tmp;
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.addDigits(38) << endl;
	return 0;
}