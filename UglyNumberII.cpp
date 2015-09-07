#include <iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
    	if (n == 1)
    		return 1;

    	int preLocate[3] = {1, 1, 1};
    	int tmp[3];

		int minLocate = 0;
		int d[n + 1];
		d[1] = 1;

    	for (int count = 2; count <= n; ++count) {
    		minLocate = 0;

    		tmp[0] = d[preLocate[0]] * 2;
    		tmp[1] = d[preLocate[1]] * 3;
    		tmp[2] = d[preLocate[2]] * 5;

    		if (tmp[0] > tmp[1]) {
    			minLocate = 1;
    		}

    		if (tmp[minLocate] > tmp[2]) {
    			minLocate = 2;
    		}

    		++preLocate[minLocate];

    		if (tmp[0] == tmp[1] && minLocate != 2) {
    			++preLocate[1 - minLocate];
    		}
    		if (tmp[minLocate] == tmp[2]) {
    			++preLocate[2];
    		}

    		d[count] = tmp[minLocate];
    	}

    	return d[n];
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.nthUglyNumber(10) << endl;
	return 0;
}