#include <vector>
#include <cstdio>

const int mv[] = {0, 8, 16, 24};

class Solution {
public:
    int maximumGap(std::vector<int> &num);
};

int Solution::maximumGap(std::vector<int> &num) {
	if (num.size() <= 1) {
		return 0;
	}

	std::vector<int> collect(num);
	std::vector<std::vector<int>> buckets(0x100, std::vector<int>());

	for (int i = 0; i < 4; ++i) {
		// clear buckets
		for (auto digit = buckets.begin(); digit != buckets.end(); ++digit) {
			digit->clear();
		}

		// enbuckets
		for (auto itr = collect.begin(); itr != collect.end(); ++itr) {
			buckets[(*itr >> mv[i]) & 0xff].push_back(*itr);
		}

		collect.clear();

		// collect
		for (auto digit = buckets.begin(); digit != buckets.end(); ++digit) {
			for (auto itr = digit->begin(); itr != digit->end(); ++itr) {
				collect.push_back(*itr);
			}
		}
	}

	int maxGap = 0;
	for (auto itr = ++collect.begin(); itr != collect.end(); ++itr) {
		if (*itr - *(itr - 1) > maxGap) {
			maxGap = *itr - *(itr - 1);
		}
	}

	return maxGap;
}

int main(int argc, char const *argv[])
{
	Solution solution;
	std::vector<int> test = {800,500,600,1000};
	printf("%d\n", solution.maximumGap(test));
	return 0;
}