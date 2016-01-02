#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
	    int counts = 0;

	    // perfect square
	    // 18 [(1, 18), (2, 9), (3, 6)]
	    // 16 [(1, 16), (2, 9), (4)]
	    for (int i = 1; i * i <= n; ++i) {
	        ++counts;    
	    }

	    return counts;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.bulbSwitch(16) << endl;
	return 0;
}