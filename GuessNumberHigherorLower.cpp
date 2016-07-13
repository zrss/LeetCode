// pay attention to this sentence -1 if MY number is lower, 1 if MY number is higher, otherwise return 0
// binary search
// ps start + end may be out of int range

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n + 1;
        
        while (start < end) {
            int mid = ((long long)start + end) >> 1;
            int result = guess(mid);
            if (result < 0) {
                end = mid;
            } else if (result == 0) {
                return mid;
            } else {
                start = mid + 1;
            }
        }
        
        return n;
    }
};