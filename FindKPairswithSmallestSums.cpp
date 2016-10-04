// in the beginning
// I would like to sort the array and use two pointers
// to track the result
// but after some cases I found that is not enough
// I should use a d[] array to record the next one position in nums2 array

// and the problem points out that nums1 and nums2 array are rank in ascending order
// so do not need to sort them again

// time complexity O(k * n)

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cctype>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

// 极大堆
struct mycmp {
    bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first + p1.second < p2.first + p2.second;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, mycmp> pq;

        int l1 = min(k, (int)nums1.size());
        int l2 = min(k, (int)nums2.size());

        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                if (pq.size() < k) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                }
                else if (nums1[i] + nums2[j] < (pq.top().first + pq.top().second)) {
                    pq.pop();
                    pq.push(make_pair(nums1[i], nums2[j]));
                }
            }
        }

        vector<pair<int, int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3}; 
    vector<pair<int, int>> result = solution.kSmallestPairs(nums1, nums2, 3);
    for (pair<int, int> each : result) {
        cout << "(" << each.first << "," << each.second << ")" << " ";
    }
    cout << endl;
    return 0;
}