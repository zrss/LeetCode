#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// 固定大小为K的最小堆

struct comp {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cntMap;
        for (int num : nums) {
            ++cntMap[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for (auto p : cntMap) {
            if (pq.size() == k) {
                if (p.second > pq.top().second) {
                    pq.pop();
                    pq.push({ p.first, p.second });
                }
            }
            else {
                pq.push({ p.first, p.second });
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            
            result.push_back(p.first);
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