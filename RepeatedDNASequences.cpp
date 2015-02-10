#include <string>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <iostream>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s);
};

std::vector<std::string> Solution::findRepeatedDnaSequences(std::string s) {
	std::vector<std::string> rel;
	if (s.length() <= 10) {
		return rel;
	}

	// map char to code
	unsigned char convert[26];
	convert[0] = 0; // 'A' - 'A'  00
	convert[2] = 1; // 'C' - 'A'  01
	convert[6] = 2; // 'G' - 'A'  10
	convert[19] = 3; // 'T' - 'A' 11

	// initial process
	// as ten length string
	int hashValue = 0;

	for (int pos = 0; pos < 10; ++pos) {
		hashValue <<= 2;
		hashValue |= convert[s[pos] - 'A'];
	}

	std::unordered_map<int, int> strTable; // strHashValue, count

	strTable.insert(std::pair<int, int>(hashValue, 1));

	// 
	for (int pos = 10; pos < s.length(); ++pos) {
		hashValue <<= 2;
		hashValue |= convert[s[pos] - 'A'];
		hashValue &= ~(0x300000);
		auto itr = strTable.find(hashValue);
		if (itr == strTable.end()) {
			strTable.insert(std::pair<int, int>(hashValue, 1));
		} else {
			if (itr->second == 1) {
				rel.push_back(s.substr(pos - 9, 10));
				++(itr->second);
			}
		}
	}

	return rel; 
}

int main(int argc, char const *argv[]) {
	Solution solution;
	std::string textStr("AAAAAAAAAAA");
	auto rel = solution.findRepeatedDnaSequences(textStr);
	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		std::cout << *itr << "\n";
	}
	return 0;
}



