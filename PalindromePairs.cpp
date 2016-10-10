class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> rmap;

		int len = words.size();
		for (int i = 0; i < len; ++i) {
			string s = words[i];
			reverse(s.begin(), s.end());
			rmap.insert({ s, i });
		}

		set<vector<int>> unique;
		for (int i = 0; i < len; ++i) {
			int clen = words[i].length();
			for (int j = 0; j <= clen; ++j) {
				string s1 = (j == 0) ? "" : words[i].substr(0, j);
				string s2 = (j == clen) ? "" : words[i].substr(j);
				if (isPalindrome(s1) && rmap.find(s2) != rmap.end() && rmap[s2] != i) {
					unique.insert({rmap[s2], i});
				}
				if (isPalindrome(s2) && rmap.find(s1) != rmap.end() && rmap[s1] != i) {
					unique.insert({i, rmap[s1]});
				}
			}
		}

		vector<vector<int>> result;
		result.assign(unique.begin(), unique.end());
		return result;
	}

	bool isPalindrome(string& str) {
		int s = 0;
		int e = str.length() - 1;

		while (s < e) {
			if (str[s] != str[e])
				return false;

			++s;
			--e;
		}

		return true;
	}
};