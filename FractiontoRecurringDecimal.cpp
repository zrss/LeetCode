#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0 || denominator == 0) { // there is a trap
            return std::to_string(0);
        }

        std::string rel;

    	if (numerator < 0 ^ denominator < 0) {
            rel += '-';
        }

        // there is another trap int -2147483648
        long num = numerator < 0 ? -((long)numerator) : numerator;
        long den = denominator < 0 ? -((long)denominator) : denominator;

        rel += std::to_string(num / den); // c++11

        // remainder
        long r = num - num / den * den;

        if (r == 0) {
            return rel;
        }

        std::unordered_map<long, int> hashMap;

        // fraction part
        std::string fpart;
        int digit = 0;

        while (r) {       
            r *= 10;

            auto itr = hashMap.find(r);

            if (itr != hashMap.end()) {
                fpart = fpart.insert(itr->second, 1, '(');
                fpart.push_back(')');
                break;
            }

            hashMap.insert(std::pair<long, int>(r, digit));
            fpart += std::to_string(r / den);
                        
            r -= (r / den * den);

            ++digit;
        }

        rel += '.';
        rel += fpart;

        return rel;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
    std::cout << solution.fractionToDecimal(1, -2147483648) << std::endl;
	return 0;
}