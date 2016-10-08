// 按先宽度升序，后高度升序排序
// 然后常规的一维DP

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		if (envelopes.size() == 0)
			return 0;
		
		sort(envelopes.begin(), envelopes.end());

		int len = envelopes.size();
		
		vector<int> dp(len, 0);
		dp[0] = 1;

		int maxEnv = 1;
		for (int i = 1; i < len; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] = max(cover(envelopes[j], envelopes[i]) ? dp[j] + 1 : 1, dp[i]);
			}
			maxEnv = max(maxEnv, dp[i]);
		}

		return maxEnv;
	}

	bool cover(pair<int, int>& e1, pair<int, int>& e2) {
		return (e1.first < e2.first && e1.second < e2.second);
	}
};