#include <string>
#include <iostream>

using namespace std;

// start 指向区间头
// cur 指向区间尾
// 当 cur 与 start 重复时
// 将 start 移动至重复元素之后

// 使用hash表保存元素下标

// -----------------------

// 当年太年轻
// 写一个更好的解法
// beats 81%

// 不需要清除之前出现的字符
// 当出现字符的index > start 时认为是重复字符
// 定向清除即可

// O(n) 复杂度

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = -1; // 不包含
		int maxLen = 0;

		int chIndex[256];
		memset(chIndex, -1, sizeof(chIndex));

		int len = s.length();
		for (int i = 0; i < len; ++i) {
			if (chIndex[s[i]] > start) {
				start = chIndex[s[i]];
			}
			chIndex[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}

		return maxLen;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	string test("abba");
	cout << solution.lengthOfLongestSubstring(test) << endl;
	return 0;
}