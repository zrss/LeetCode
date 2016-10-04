#include <iostream>

using namespace std;

// once time I just want to use ^ to add bit by bit
// but how to express in becomes a hard problem for me
// as you can see
// in, pA, pB
// 0 0 0 pR 0 in 0
// 1 1 1 pR 1 in 1
// two ones pR 0 in 1
// one one pR 1 in 0

// discuss show me a great method
// what a genius guy who thought of this method
// a ^ b keep the different bit i.e. add without in
// but a & b keep the same bit, then shift to left one, i.e. in
// so doing (a ^ b) ^ ((a & b) << 1) while ((a & b) != 0)
// then a ^ b is the final result

// a trick problem

// but how to handle negative number
// okay how computer to do the minus
// just like the plus
// use complement
// x is negative
// then the complement of x is ~(-x) + 1

// x + y
// ~(-x) + 1 + y

// 位操作
// 对应位都为 1 才进位

class Solution {
public:
    int getSum(int a, int b) {
        if (a < 0) {
            a = -a;
            a = ~a + 1;
        }
        if (b < 0) {
            b = -b;
            b = ~b + 1;
        }
        while (b != 0) {
            int addWithoutIn = a ^ b;
            int in = (a & b) << 1;
            a = addWithoutIn;
            b = in;
        }
        return a;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.getSum(0, 0) << endl;
    return 0;
}