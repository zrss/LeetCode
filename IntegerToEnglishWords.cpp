#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        // 0 check
        if (num == 0) {
            return "Zero";
        }

        string rel;
        if (num > 999999999) {
            rel += convert(num / 1000000000) + " Billion";
            num %= 1000000000;

            if (num == 0) {
                return rel;
            }

            rel += " ";
        }

        if (num > 999999) {
            rel += convert(num / 1000000) + " Million";
            num %= 1000000;

            if (num == 0) {
                return rel;
            }

            rel += " ";
        }

        if (num > 999) {
            rel += convert(num / 1000) + " Thousand";
            num %= 1000;

            if (num == 0) {
                return rel;
            }

            rel += " ";
        }

        rel += convert(num);
        return rel;
    }

    // num < 1000
    string convert(int num) {
    	string value[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    	string special[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                "Seventeen", "Eighteen", "Nineteen"};

    	string tenTimes[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    	string rel;

    	if (num >= 100) {
    		rel += value[(num / 100) - 1];
    		rel += " Hundred";
    		num %= 100;

            if (num == 0) { // 整百
                return rel;
            }

            rel += " ";
    	}

    	if (num % 10 == 0) { // 整十
    		rel += tenTimes[(num / 10) - 1];
    		return rel;
    	}

    	if (num >= 11 && num <= 19) { // 特殊
    		rel += special[(num % 10) - 1];
    		return rel;
    	}

    	if (num > 10) {
    		rel += tenTimes[(num / 10) - 1];
    		num %= 10;

            if (num == 0) {
                return rel;
            }

            rel += " ";
    	}

    	rel += value[num - 1];
    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.numberToWords(1000000000) << endl;
	return 0;
}