#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// F(3) = F(1) + F(2)
// F(4) = F(1) + 2F(2)
// F(5) = 2F(1) + 3F(2)
// F(6) = 3F(1) + 5F(2)

// 可能的长度
// F(1)'s len <= len >> 1

// 假设len = 9
// F(1)'s len 若取5位
// F(3)'s len 至少是5位数，那么就超过了len，所以F(1)'s len <= len >> 1

// len为偶数也是一样的情况

// F(2)'s len <= (len - 1) >> 1
// 假设len = 8
// F(1)'s len 若取1位
// F(2)'s len 若取4位
// F(3)'s len 至少是4位数，那么就超过了len，所以F(2)'s len <= (len - 1) >> 1

// 直接模拟求解
// 遍历
// 复杂度
// n^3

class Solution {
public:
	bool isAdditiveNumber(string num) {
		if (num.size() < 3) {
			return false;
		}

		for (int i = 1; i <= num.size() >> 1; ++i) {
			for (int j = 1; j <= (num.size() - 1) >> 1; ++j) {
				if (helper(i, j, num) == 0) {
					return true;
				}
			}
		}

		return false;
	}

	int helper(int f1len, int f2len, string& num) {
		if ((num[0] == '0' && f1len != 1) || (num[f1len] == '0' && f2len != 1)) {
			return -3; // F(1) leading 0 || F(2) leading 0
		}

		int start = 0;

		while (start + f1len + f2len < num.length()) {
			string f1(num.begin() + start, num.begin() + start + f1len);
			string f2(num.begin() + start + f1len, num.begin() + start + f1len + f2len);

			string f3 = bigNumberAdd(f1, f2);

			if (start + f1len + f2len + f3.length() < num.length()) {
				string real(num.begin() + start + f1len + f2len, num.begin() + start + f1len + f2len + f3.length());
				if (f3 != real) {
					return -2; // not match
				}
			}
			else if (start + f1len + f2len + f3.length() == num.length()) {
				string real(num.begin() + start + f1len + f2len, num.begin() + start + f1len + f2len + f3.length());
				if (f3 != real) {
					return -2; // not match
				}
				else {
					return 0; // match
				}
			}
			else {
				return -2;
			}

			start += f1len;
			f1len = f2len;
			f2len = f3.length();
		}

		return 0;
	}

	string bigNumberAdd(string a, string b) {
		int maxLen = a.length() < b.length() ? b.length() : a.length();
		vector<int> aNum(maxLen + 1, 0);
		vector<int> bNum(maxLen + 1, 0);

		for (int i = (int)a.length() - 1, pos = 0; i >= 0; --i) {
			aNum[pos++] = a[i] - '0';
		}
		for (int i = (int)b.length() - 1, pos = 0; i >= 0; --i) {
			bNum[pos++] = b[i] - '0';
		}

		for (int i = 0; i < maxLen; ++i) {
			aNum[i] += bNum[i];
			aNum[i + 1] += aNum[i] / 10;
			aNum[i] %= 10;
		}

		int start = maxLen;
		while (start > 0 && aNum[start] == 0) {
			--start;
		}

		string rel;
		for (int i = start; i >= 0; --i) {
			rel.push_back((char)(aNum[i] + '0'));
		}

		return rel;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.isAdditiveNumber("121474836472147483648") << endl;
	return 0;
}