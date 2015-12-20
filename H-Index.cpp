#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	sort(citations.begin(), citations.end());

    	int maxH = 0;

    	for (int i = citations.size() - 1; i >= 0; --i) {
    		int order = citations.size() - i;
    		int tmp = min(citations[i], order);
    		if (tmp > maxH) {
    			maxH = tmp;
    		}
    	}

    	return maxH;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> citations = {1, 2};
	cout << solution.hIndex(citations) << endl;
	return 0;
}