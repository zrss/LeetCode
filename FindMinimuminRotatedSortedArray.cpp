#include <vector>
#include <cstdio>

class Solution {
public:
    int findMin(std::vector<int> &num) {
        int l = 0;
        int u = num.size() - 1;

        while (l < u) {
            int mid = (l + u) >> 1;
            if (num[l] < num[u]) {
                return num[l];
            }
            if (num[mid] > num[u]) {
                l = mid + 1;
            } else {
                u = mid;
            }
        }

        return num[l];
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	std::vector<int> test = {4,5,6,7,1,2,3};
	printf("%d\n", solution.findMin(test));
	return 0;
}