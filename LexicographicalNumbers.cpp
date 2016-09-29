#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
		vector<int> rel;
		lexicalOrder(n, 1, 9, rel);
		return rel;
    }

    void lexicalOrder(int target, int base, int cnt, vector<int>& rel) {
		for (int i = 0; base <= target &&  i < cnt; ++i, ++base) {
			rel.push_back(base);
			if (base * 10 <= target) {
				lexicalOrder(target, base * 10, 10, rel);
			}
		}
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> rel = solution.lexicalOrder(13);
	for (int each : rel) {
		cout << each << " ";
	}
	cout << endl;
	return 0;
}