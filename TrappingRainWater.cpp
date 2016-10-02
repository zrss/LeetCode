#include <iostream>
#include <vector>

using namespace std;

// 计算每个格子的藏水量 cur
// 与该格子的左边最高的隔板高度 lmax
// 及该格子的右边最高的隔板高度 rmax 有关 
// 藏水量为 min(lmax, rmax) - cur

// 双指针扫描
// Time O(n)
// Space O(1)

class Solution {
public:
    /**
    * @param heights: a vector of integers
    * @return: a integer
    */
    int trapRainWater(vector<int> &heights) {
        // write your code here

        int l = 0;
        int r = heights.size() - 1;

        int lmax = 0;
        int rmax = 0;

        int water = 0;
        while (l < r) {
            lmax = max(lmax, heights[l]);
            rmax = max(rmax, heights[r]);

            if (lmax < rmax) {
                water += (lmax - heights[l++]);
            }
            else {
                water += (rmax - heights[r--]);
            }
        }
        
        return water;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << solution.trap(height) << endl;
	return 0;
}