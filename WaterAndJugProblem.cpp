#include <iostream>
#include <unordered_set>

using namespace std;

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