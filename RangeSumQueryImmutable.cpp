#include <iostream>
#include <vector>

using namespace std;

// 最直接想法
// 预计算[i, j]的和
// 预计算复杂度O(n^2)
// sumRange复杂度O(1)

// 超时
// 是否有更合适的数据结构
// 似乎并没有

// 好吧
// 似乎第i位存储前i位的和即可
// 预计算复杂度O(n)
// sumRange复杂度O(1)

// 额，还是一道easy的题，思维果然是有局限性的啊

class NumArray {
public:
    NumArray(vector<int> &nums) {
        cache = new vector<int>(nums.size(), 0);
        vector<int>& rCache = *cache;

    	int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
        	sum += nums[i];
        	rCache[i] = sum;
        }
    }

    int sumRange(int i, int j) {
    	if (i <= j) {
    		if (i != 0) {
        		return (*cache)[j] - (*cache)[i - 1];
    		} else {
        		return (*cache)[j];
    		}
    	}
    	return 0;
    }

    ~NumArray() {
    	delete cache;
    }

private:
	vector<int>* cache;
};

int main() {
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
	NumArray solution(nums);
	cout << solution.sumRange(2, 5) << endl;
	return 0;
}