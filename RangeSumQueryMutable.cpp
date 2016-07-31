#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
        	index.push_back(sum);
        	sum += nums[i];
        }
        index.push_back(sum);
    }

    void update(int i, int val) {
    	int diff = val - (index[i + 1] - index[i]);
        for (int j = i + 1; j < index.size(); ++j) {
        	index[j] += diff;
        }
    }

    int sumRange(int i, int j) {
        return index[j] - index[i];
    }

private:
	vector<int> index;
};

int main(int argc, char const *argv[]) {
	vector<int> nums = {1,3,5};
	NumArray numArray(nums);

	cout << numArray.sumRange(0, 1) << endl;

	numArray.update(1, 10);

	cout << numArray.sumRange(1, 2) << endl;
	return 0;
}


