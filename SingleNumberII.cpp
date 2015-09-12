#include <cstdio>

class Solution {
public:
    int singleNumber(int A[], int n) {
		int itr = 0;
		for (int i = 0; i < n; ++i) {
			itr ^= A[i];
		}

		for (int i = 0; i < n; ++i) {
			itr ^= A[i];
		}

		printf("%d\n", itr); 
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int A[] = {2,2,2,3,3,3};
	solution.singleNumber(A, 7);
	return 0;
}