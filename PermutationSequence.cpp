#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 很神奇的算法
// 利用阶乘
// 并且找规律

class Solution {
public:
    string getPermutation(int n, int k) {
        string rel;
        vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

        while (n) {
        	int tmp = (k - 1) / factorial[n - 1];
        	rel += (num[tmp] + '0');
        	num.erase(num.begin() + tmp);
        	k -= tmp * factorial[n - 1];
        	--n;
        }

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.getPermutation(4, 3) << endl;
	return 0;
}