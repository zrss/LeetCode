#include <iostream>
#include <string>

using namespace std;

// 特殊情况的处理

class Solution {
public:
    string convertToTitle(int n) {
    	char map[] ={'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
    			'S', 'T', 'U', 'V', 'W', 'X', 'Y'};

    	string tmp;

    	while (n > 0) {
    		tmp.push_back(map[n % 26]);
    		n = n % 26 ? n / 26 : n / 26 - 1;
    	}

    	string rel;
    	for (int i = tmp.length() - 1; i >= 0; --i) {
    		rel.push_back(tmp[i]);
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.convertToTitle(703) << endl;
	return 0;
}