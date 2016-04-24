#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 方法1
// 枚举[x, y, z]
// for 
//     for
//         for
// O(n^3)

// 方法2
// 排序
// 枚举x
// y = x + 1
// z = end - 1
// sum = x + y + z
// sum == 0，找到符合条件的解，之后注意跳过相同元素
// sum > 0，--z
// sum < 0，++y
// O(n^2)

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > rel;

    	if (num.size() == 0) {
    		return rel;
    	}

        sort(num.begin(), num.end());

        int cnt = num.size();
        int pre = num[0] - 1;

        for (int x = 0; x < cnt - 2; pre = num[x], ++x) {
        	if (num[x] == pre) {
        		continue;
        	}

        	int y = x + 1;
        	int z = cnt - 1;

        	while (y < z) {
	        	// if (x == 0 && y == 4) {
        		// 	cout << "hit" << endl;	
        		// }

        		int sum = num[x] + num[y] + num[z];

        		// cout << x << " " << y << " " << z << " " << sum << endl;

        		if (sum == 0) {
        			vector<int> cur = {num[x], num[y], num[z]};
        			rel.push_back(cur);

        			do {
        				--z;
        			} while (y < z && (num[z] == num[z + 1]));

        			do {
        				++y;
        			} while (y < z && (num[y] == num[y - 1]));

        		} else if (sum < 0) {
        			++y;
        		} else {
        			--z;
        		}
        	}
        }

        return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<int> num = {-1, 0, 1, 2, -1, -4};
	vector<vector<int> > rel = solution.threeSum(num);

	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		for (auto each = itr->begin(); each != itr->end(); ++each) {
			cout << *each << " ";
		}
		cout << endl;
	}
	return 0;
}