#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 格雷码生成规则

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> rel(1, 0);

    	if (n == 0) {
    		return rel;
    	}

    	int gray = 0;
    	int pos;

    	do {
	    	gray ^= 1;
	    	rel.push_back(gray);

	    	pos = 0;
	    	int flag = 1;
	    	while ((flag & gray) == 0) {
	    		flag <<= 1;
	    		++pos;
	    	}
	    	flag <<= 1;

	    	gray ^= flag;
	    	rel.push_back(gray);

    	} while (pos < n - 1);

    	rel.pop_back();

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> rel = solution.grayCode(2);
	for (auto each : rel) {
		cout << each << endl;
	}
	return 0;
}