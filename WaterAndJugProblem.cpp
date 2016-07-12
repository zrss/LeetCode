#include <iostream>
#include <unordered_set>

using namespace std;

// what a hard problem -_-
// kill my whole morning spare time
// I spend so much time hand write that transform
// finally get a regular for programm to implement it
// abstract some denotes from problem

// target z, num b1, num b2

// assert that b1 < b2

// then do following operate
// pour b1 to b2
// refill b1 then pour b1 to b2
// that remain in b1 denotes itr = b1 - (b2 - b1)

// it seems like a iterate process

// so I initial itr = b1
// then do the following process
// if b1 > (b2 - itr)
// then we can get b1 - (b2 - itr) and b1 - (b2 - itr) + b2 i.e. b1 + itr
// else b1 <= b2 - itr
// then we can get b1 + itr, as b1 can not fill b2 with itr
// continue this process to find all the num we can get, if once itr repeat again then
// we can stop this process

// okay, speed is far too slow
// okay, view the discuss, omg, it is a GCD problem -_-

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z < 0 || z > (x + y)) {
            return false;
        }

        if (z == 0) {
            return true;
        }

        if (x == y) {
            if (z == x || z == (x << 1)) {
                return true;
            }
            return false;
        }

        int b1 = x;
        int b2 = y;

        if (b2 < b1) {
            swap(b1, b2);
        }

        // assert b1 < b2
        unordered_set<int> set;
        int itr = b1;

        while (true) {
            int fillGap = b2 - itr;
            if (b1 > fillGap) {
                itr = b1 + itr - b2;
                // cout << itr << " " << itr + b2 << endl;
                if (itr == z || itr + b2 == z) {
                    return true;
                }
                if (set.find(itr) == set.end()) {
                    set.insert(itr);
                } else {
                    break;
                }
            } else {
                itr = b1 + itr;
                // cout << "0" << " " << itr << endl;
                if (itr == z) {
                    return true;
                }
                if (set.find(itr) == set.end()) {
                    set.insert(itr);                    
                } else {
                    break;
                }
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.canMeasureWater(3, 3, 4) << endl;
    return 0;
}