#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
	Solution():maxLen(0) {};

    std::string longestPalindrome(std::string s);

private:
	void calPalindrome(std::string& s, int len, int left, int right);

private:
	std::string rel;
	int maxLen;
};

void Solution::calPalindrome(std::string& s, int len, int left, int right) {
    while (left >= 0 && right < s.length() && (s[left] == s[right])) {
		len += 2;
		--left;
		++right;
	}

	if (len > maxLen) {
		maxLen = len;
		rel = s.substr(left + 1, len);
	}
}

std::string Solution::longestPalindrome(std::string s) {
	// there is a trap when s is a single char
	if (s.length() <= 1) {
		return s;
	}

	for (int i = 0; i < s.length(); ++i) {
		calPalindrome(s, 0, i, i + 1); // even length
		calPalindrome(s, 1, i - 1, i + 1); // odd length
	}

	return rel;
}

int main(int argc, char const *argv[])
{
	Solution solution;
	std::string test("fsdajfdsjlll");
	std::cout << solution.longestPalindrome(test) << std::endl;
	return 0;
}