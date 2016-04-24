#include <iostream>
#include <string>

using namespace std;

// 减法游戏

class Solution {
public:
    string intToRoman(int num) {
        string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; // 相当于十三位
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; // 相应数值

        string rel;
        if (num <= 0) {
        	return rel;
        }
        
        for (int i = 0; i < 13; ++i) {
            // 如果大于最高位的最大值
            // 则持续减
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