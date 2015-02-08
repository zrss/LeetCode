#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

class Integer {
public:	
	Integer(int i);

	int getCount() { return count; }

	int next() {
		if (!tmp_count) {
			tmp_count = count;
		}
		return digits[--tmp_count];
	}

private:
	int _i;
	int count;
	int tmp_count;
	int digits[10];
};

Integer::Integer(int i):count(0),tmp_count(0) { // there has a great trap when i == 0
	if (i) {
		while (i) {
			digits[count++] = i % 10;
			i /= 10;
		}
	} else {
		++count;
		digits[0] = 0;
	}
	tmp_count = count;
}

bool cmp(const int& a, const int& b) {
	Integer ia(a);
	Integer ib(b);

	int maxCmpCount = ia.getCount() + ib.getCount();
	int curCmpCount = 0;

	while (curCmpCount < maxCmpCount) {
	 	int bita = ia.next();
		int bitb = ib.next();
		
		if (bita > bitb) {
			return true;
		}

		if (bita < bitb) {
			return false;
		}

		++curCmpCount;
	}

	return false;
}

class Solution {
public:
    std::string largestNumber(std::vector<int> &num) {
    	// there is a trap when nums is all zero
    	bool allZero = true;
    	for (auto itr = num.begin(); allZero && itr != num.end(); ++itr) {
    		if (*itr != 0) {
    			allZero = false;
    		}
    	}

    	if (allZero) {
    		return std::string("0");
    	}

    	std::sort(num.begin(), num.end(), cmp);
    	std::string rel;
    	char tmp[10];
    	for (auto itr = num.begin(); itr != num.end(); ++itr) {
    		sprintf(tmp, "%d", *itr);
    		rel += tmp;
    	}
    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	std::vector<int> nums = {33,333};
	std::cout << solution.largestNumber(nums);
	return 0;
}