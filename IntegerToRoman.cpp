#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string rel;
        if (num <= 0) {
        	return rel;
        }
        
        for (int i = 0; i < 13; ++i) {
        	while (num >= value[i]) {
        		num -= value[i];
        		rel += str[i];
        	}
        	if (!num) {
        		return rel;
        	}
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.intToRoman(1954) << endl;
	return 0;
}