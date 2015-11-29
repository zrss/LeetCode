#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int l = 0, r = height.size() - 1;
        int max = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                int tmp = height[l] * (r - l);
                if (tmp > max) {
                    max = tmp;
                }
                int low = height[l];
                while (l < r && height[++l] <= low);
            } else {
                int tmp = height[r] * (r - l);
                if (tmp > max) {
                    max = tmp;
                }
                int low = height[r];
                while (l < r && height[--r] <= low);
            }
        }

        return max;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> height = {1, 2, 4, 6, 1};
	cout << solution.maxArea(height) << endl;
	return 0;
}