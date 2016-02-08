#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    	if (height.size() == 0) {
    		return 0;
    	}

    	int water = 0;
    	int preIndex = 0;
    	int preHeight = 0;

    	// 找到第一个高度非0的bar
    	while (preIndex < height.size() - 1 && height[preIndex] == 0) {
    		++preIndex;
    	}

    	if (preIndex == height.size() - 1) {
    		return 0;
    	}

    	// 遍历
    	while (preIndex < height.size()) {
    		preHeight = height[preIndex];

    		// 寻找更高的或相等的bar
    		// 同时记录遍历过的最高的bar
    		// 如果寻找不到更高的或相等的bar时，使用记录值计算
    		int next = preIndex + 1;
    		int minHeight = 0;
    		int minIndex = next;

	    	while (next < height.size() && height[next] < preHeight) {
	    		if (height[next] > minHeight) {
	    			minHeight = height[next];
	    			minIndex = next;
	    		}
	    		++next;
	    	}

	    	// 如果找到
	    	if (next != height.size()) {
	    		water += (preHeight * (next - preIndex - 1)); // 计算总面积

	    		for (int i = preIndex + 1; i < next; ++i) { // 减去中间bar面积
	    			water -= height[i];
	    		}

	    		preIndex = next; // 从找到的bar开始下一次的迭代
	    	} else {
	    		water += (minHeight * (minIndex - preIndex - 1)); // 计算总面积

	    		for (int i = preIndex + 1; i < minIndex; ++i) { // 减去中间bar面积
	    			water -= height[i];
	    		}

	    		preIndex = minIndex; // 从次高的bar开始
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