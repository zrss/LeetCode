#include <cstdio>

class Solution {
public:
    int maxProduct(int A[], int n) {
    	int max[n] = A[0];
        int min[n] = A[0];

        for (int i = 1; i < n; ++i) {
            if (max[i - 1] * A[i] > min[i - 1])
        }

    	

    	return max;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int A[] = {2,3,-2,-2,4};
	printf("%d\n", solution.maxProduct(A, 4));
	return 0;
}