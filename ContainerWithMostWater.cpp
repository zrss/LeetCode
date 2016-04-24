#include <iostream>
#include <vector>

using namespace std;

// 方法1
// 简单粗暴
// 枚举[i, j]组合
// O(N^2)

// 方法2
// 木桶原理，很高大上对吧
// 其实吧是因为[i, j]组合能容纳的水的多少和min(h[i], h[j])有关
// 即只与短的木板有关系

// 所以只需移动短板就可以找到最大的蓄水量了
// 双指针
// l = 0, r = len - 1

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int l = 0, r = height.size() - 1;
        int rel = 0;

        while (l < r) {
            rel = max(rel, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> height = {1, 2, 4, 6, 1};
	cout << solution.maxArea(height) << endl;
	return 0;
}