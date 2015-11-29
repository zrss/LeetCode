#include <iostream>
#include <vector>
#include <stack>

// reference http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int i = 0;
        int cnt = height.size();
        int maxArea = 0;

        stack<int> stack;

        while (i < cnt) {
            if (stack.empty() || height[stack.top()] <= height[i]) {
                stack.push(i++);
            } else {
                int tp = stack.top();
                stack.pop();

                int area = height[tp] * (stack.empty() ? i : (i - stack.top() - 1));

                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }

        while (!stack.empty()) {
            int tp = stack.top();
            stack.pop();

            int area = height[tp] * (stack.empty() ? i : (i - stack.top() - 1));

            if (area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> height = {2,1,5,6,2,3};
	cout << solution.largestRectangleArea(height) << endl;
	return 0;
}