// 分治的思想
class Solution {
public:
	int longestSubstring(string s, int k) {
		int len = s.length();
		if (len == 0 || k > len)
			return 0;

		int chCnt[26];
		memset(chCnt, 0, sizeof(chCnt));

		int i = 0;
		while (i < len) {
			++chCnt[s[i] - 'a'];
			++i;
		}

		i = 0;
		while (i < len && chCnt[s[i] - 'a'] >= k) {
			++i;
		}

		if (i == len)
			return s.length();

		// 如果 chCnt[i] < k 说明 s[i] 不会在结果中因此
		return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i + 1), k));
	}
};