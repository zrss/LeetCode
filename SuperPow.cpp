// okay seems another math problem

// a^b % c problem
// when b is large enough
// we have to considerate math theory
// (A * B) % C = ((A % C) * (B % C)) % C
// (3 * 5) % 4 = ((3 % 4) * (5 % 4)) % 4 = 3

// so
// a ^ b % c = ((a ^ (b / 2)) % c * (a ^ (b / 2)) % c) % c if b is even
// denote a ^ (b / 2) % c = half
// if b is odd
// a ^ b % c = (half * half * a) % c
// if b is even
// a ^ b % c = (half * half) % c


// recursion programm is straight forward but how to do it in iterate style
// notes that / 2 equal to right shift one bit
// and even and odd can check by num & 0x01

// so
// int ans = 1
// int itr = a % c
// if b ^ 1 == 1
// ans = ans * a % c
// else
// itr = itr * itr % c

// how stupid i am
// i try to solve in

// int itr = 1
// if b ^ 1 == 1
// ans = itr * itr * a % c
// else
// itr = itr * itr % c

// but die in have to reverse b and keep the bit number of b

// as for this problem
// a^5374
// (a^1000)^5 * (a^100)^3 * (a^10)^7 * (a^1)^4
// a^10^n (n = 0, 1, ...) as index
// straight forward method
// notice may be out of int range

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int c = 1337;

        long long current = 1;
        int index = a;
        for (int s = b.size() - 1; s >= 0; --s) {
            for (int i = 0; i < b[s]; ++i) {
                current *= index;
                current %= c;
            }
            long long tmpIndex = 1;
            for (int i = 0; i < 10; ++i) {
                tmpIndex *= index;
                tmpIndex %= c;
            }
            index = tmpIndex;
        }

        return current;
    }

    // recursion
    int congruence(int a, int b, int c) {
        if (b == 1) {
            return a % c;
        }
        int half = congruence(a, b / 2, c) % c;
        return b & 1 ? half * half * a % c : half * half % c;
    }

    // iterate
    int congruenceByIterate(int a, int b, int c) {
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> b = {0, 0, 0, 0};
    cout << solution.superPow(2, b) << endl;
    return 0;
}