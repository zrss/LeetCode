#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int* win;

bool comp(const int& iA, const int& iB) {
	return win[iA] < win[iB];
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	if (nums.size() == 0) {
    		return vector<int>();
    	}

    	int* indexHeap = new int[k];
 		win = new int[k];

 		for (int i = 0; i < k; ++i) {
 			indexHeap[i] = i;
 			win[i] = nums[i];
 		}

 		int iWin = -1;
 		int final = nums.size() - k + 1;

 		vector<int> rel;
 		rel.reserve(final);

 		for (int i = 0; i < final - 1; ++i) {
 			make_heap(indexHeap, indexHeap + k, comp);
 			rel.push_back(win[indexHeap[0]]);
 			++iWin;
 			iWin %= k;
 			win[iWin] = nums[i + k];
 		}

 		make_heap(indexHeap, indexHeap + k, comp);

 		rel.push_back(win[indexHeap[0]]);

 		delete [] indexHeap;
 		delete [] win;

 		return rel;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	vector<int> nums = {1,3,1,2,0,5};

	vector<int> rel = solution.maxSlidingWindow(nums, 3);

	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;

	return 0;
}