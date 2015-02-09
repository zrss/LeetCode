#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s);

    ~Solution();

private:
	std::size_t* next;
};

std::vector<std::string> Solution::findRepeatedDnaSequences(std::string s) {
	std::vector<std::string> rel;

	if (s.length() <= 10) {
		return rel;
	}

	next = new std::size_t[s.length()];

	// cal next array
	for (int pos = 0; pos < s.length(); ++pos) {
		next[pos] = s.find_first_of(s[pos], pos + 1);
	}

	for (int pos = 0; pos < s.length(); ++pos) {
		std::size_t nextPos = next[pos];
		while (nextPos != std::string::npos) {
			int ic = pos;
			int in = nextPos;
			int count = 0;
			while (in != s.length() && count < 9 && s[++ic] == s[++in]) {
				++count;
			}
			if (count == 9) {
				std::string tmp = s.substr(pos, 10);
				bool repeat = false;
				for (auto itr = rel.begin(); !repeat && itr != rel.end(); ++itr) {
					if (*itr == tmp) {
						repeat = true;
					}
				}
				if (!repeat) {
					rel.push_back(tmp);
				}
			}
			nextPos = next[nextPos];
		}
	}

	return rel;
}

Solution::~Solution() {
	delete [] next;
}

int main(int argc, char const *argv[]) {
	Solution solution;
	std::string textStr("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	auto rel = solution.findRepeatedDnaSequences(textStr);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		std::cout << *itr << "\n";
	}
	return 0;
}



