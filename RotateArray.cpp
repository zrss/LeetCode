#include <cstdio>

class Solution {
public:
    void rotate(int nums[], int n, int k) {
    	k %= n; // there is a trap

    	if (k == 0) { // there is a trap when k == 0
    		return;
    	}

    	int gap = n - k; 
        inverse(nums, 0, gap);
        inverse(nums, gap, n);
        inverse(nums, 0, n);
    }

    void inverse(int nums[], int s, int e) {
    	--e;
    	while (s < e) {
    		int tmp = nums[s];
    		nums[s] = nums[e];
    		nums[e] = tmp;
    		++s;
    		--e;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int nums[] = {1,2,3,4,5,6,7,8,9,10};
	solution.rotate(nums, 10, 3);
	for (int i = 0; i < 2; ++i) {
		printf("%d ", nums[i]);
	}
	return 0;
}