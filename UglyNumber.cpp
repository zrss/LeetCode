#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	if (num == 0) { // check
    		return false;
    	}

        int factor[3] = {2, 3, 5};
        bool cont = true;

        while (cont && num != 1) {
        	int i = 0;
        	bool div = false;

        	while (!div && i < 3) {
        		if (num % factor[i] == 0) {
        			num /= factor[i];
        			div = true;
        		}
    			++i;
        	}

        	if (!div) {
        		cont = false;
        	}
        }

        return cont;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.isUgly(0) << endl;
	return 0;
}