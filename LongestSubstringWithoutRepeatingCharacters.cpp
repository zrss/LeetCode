#include <string>
#include <iostream>

using namespace std;

// start 指向区间头
// cur 指向区间尾
// 当 cur 与 start 重复时
// 将 start 移动至重复元素之后

// 使用hash表保存元素下标

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0;
		int cur = 0;
		int maxLen = 0;

		int hashTable[256];
		memset(hashTable, 0, sizeof(hashTable));

		while (!(s.length() - start < maxLen)) { // 可能的最大不重复子串长度 >= maxLen
			while (cur < s.length() && hashTable[s[cur]] == 0) {
				hashTable[s[cur]] = cur + 1; // 下标 + 1
				++cur;
			}

			int tmpLen = cur - start;
			if (tmpLen > maxLen) {
				maxLen = tmpLen;
			}

			if (cur == s.length()) {
				break;
			}

			int tmp = hashTable[s[cur]];

			// 清除之前出现的元素
			for (int i = start; i < hashTable[s[cur]]; ++i) {
				hashTable[s[i]] = 0;
			}

			start = tmp;
		}

		return maxLen;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	string test("anviaj");
	cout << solution.lengthOfLongestSubstring(test) << endl;
	return 0;
}