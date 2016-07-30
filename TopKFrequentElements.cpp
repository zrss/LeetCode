#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// reverse with sort
// min heap

struct cmp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> element_cnt;
        for (int i = 0; i < nums.size(); ++i) {
            ++element_cnt[nums[i]];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;
        for (auto itr = element_cnt.begin(); itr != element_cnt.end(); ++itr) {
            min_heap.push(pair<int, int>(itr->first, itr->second));
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back((min_heap.top()).first);
            min_heap.pop();
        }

        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> nums = {};
    vector<int> result = solution.topKFrequent(nums, 3);
    for (auto each : result) {
        cout << each << " ";
    }
    cout << endl;
    return 0;
}