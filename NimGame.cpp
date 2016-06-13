/*

	Math Game
	once you can pick 1, 2, 3
	so let the second guy to pick the final three number then you can win
	as
	1, 2, 3, 4, 5
	let the second guy to pick 2, 3, 4
	you pick 1
	then you can win

	convert to math problem it is whether n is divide by 4

*/

class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0) {
            return false;
        }
        return true;
    }
};