#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0) {
			return 0;
		}

		int start = 0;
		int end = str.length();
		bool negative = false;

		// 删除首尾空格
		while (str[start] == ' ' && start < end) {
			++start;
		}

		if (start == end) {
			return 0;
		}

		while (str[end - 1] == ' ' && end >= 0) {
			--end;
		}

		// 是否有符号位
		if (str[start] == '+') {
			++start;
		}
		else if (str[start] == '-') {
			negative = true;
			++start;
		}

		// 跳过前导 0
		for (; start < str.length(); ++start) {
			if (str[start] != '0') {
				break;
			}
		}

		// 全0
		if (start == str.length()) {
			return 0;
		}

		// 提取有效数字
		for (int i = start; i < end; ++i) {
			if (str[i] < '0' || str[i] > '9') {
				end = i;
				break;
			}
		}

		if (start == end) {
			return 0;
		}

		// 溢出检查
		if (end - start > 10) {
			return negative ? -2147483648 : 2147483647;
		}

		if (end - start == 10) {
			char Max[] = "2147483647";
			int i = start;
			for (; i < end - 1; ++i) {
				if (str[i] > Max[i - start]) {
					return negative ? -2147483648 : 2147483647;
				} else if (str[i] < Max[i - start]) {
					break;
				}
			}

			if (i == end - 1) {
				if (negative) {
					if (str[end - 1] >= '8') {
						return -2147483648;
					}
				} else {
					if (str[end - 1] >= '7') {
						return 2147483647;
					}
				}
			}
		}

		// 计算转换结果
		int num = 0;

		while (start < end) {
			num *= 10;
			num += (str[start] - '0');
			++start;
		}

		return negative ? -num : num;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.myAtoi("     +004500") << endl;
	return 0;
}