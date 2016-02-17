#include <iostream>

using namespace std;

bool isBadVersion(int version) {
    if (version <= 1702766718) {
        return false;
    }
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        // n >= 1
        int low = 1;
        int high = n;

        while (low < high) {
            int mid = ((long long)low + high) >> 1; // low + high maybe overflow
            if (isBadVersion(mid)) {
                high = mid;
            } else {
               low = mid + 1;
            }
        }

        return low;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.firstBadVersion(2126753390) << endl;
    return 0;
}