// 偷懒
// 用了 set
// 和 优先队列

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> nset;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nset.find(nums[i]) == nset.end()) {
                if (pq.size() < 3) {
                    pq.push(nums[i]);
                    nset.insert(nums[i]);
                } else {
                    if (nums[i] > pq.top()) {
                        nset.erase(pq.top());
                        pq.pop();
                        pq.push(nums[i]);
                        nset.insert(nums[i]);
                    }
                }
            }
        }
        if (pq.size() == 3)
            return pq.top();
        if (pq.size() == 2)
            pq.pop();
        return pq.top();
    }
};