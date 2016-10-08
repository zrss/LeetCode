/*讨论区，有人给出了参考最长上升子序列的思路（可以优化到ＮlogN），只不过是二维，需要一些额外的考虑。

排序时，先按宽度升序排序，保证从左向右遍历时，宽度是符合条件的。若宽度相等，则按高度降序排序。这样子从左向右遍历时，宽度可视作满足要求，
使用高度作为LIS，这样保证LIS的最后一个元素尽可能小即可。*/


bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int size = envelopes.size();
		sort(envelopes.begin(), envelopes.end(), cmp);

		vector<int> collector;
		for (auto& pair : envelopes) {
			auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
			if (iter == collector.end()) collector.push_back(pair.second);
			else if (*iter > pair.second) *iter = pair.second;
		}

		return collector.size();
	}
};