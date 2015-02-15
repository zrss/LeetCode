#include <vector>
#include <cstdio>

class Solution {
public:
    int maximumGap(std::vector<int> &num) {
    	if (num.size() <= 1) {
    		return 0;
    	}

    	// radix sort
    	std::vector<int> collect(num);
    	std::vector<std::vector<int>> buckets(10, std::vector<int>());

    	// cal collect time
    	int max = 0;
    	for (auto itr = collect.begin(); itr != collect.end(); ++itr) {
    		if (*itr > max) {
    			max = *itr;
    		}
    	}

    	int count = 0;
    	while (max) {
    		++count;
    		max /= 10;
    	}

    	int i = 0;
    	int val = 1;

    	while (i < count) {
	    	for (auto digit = buckets.begin(); digit != buckets.end(); ++digit) {
	    		digit->clear();
	    	}

    		// enbuckets
	    	for (auto itr = collect.begin(); itr != collect.end(); ++itr) {
	    		buckets[(*itr / val) % 10].push_back(*itr);
	    	}

	    	collect.clear();

	    	// collect
	    	for (auto digit = buckets.begin(); digit != buckets.end(); ++digit) {
	    		for (auto itr = digit->begin(); itr != digit->end(); ++itr) {
	    			collect.push_back(*itr);
	    		}
	    	}

	    	val *= 10;
	    	++i;
    	}

    	//
    	int maxGap = 0;

    	for (auto itr = ++collect.begin(); itr != collect.end(); ++itr) {
    		if (*itr - *(itr - 1) > maxGap) {
    			maxGap = *itr - *(itr - 1);
    		}
    	}

    	return maxGap; 	
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	std::vector<int> test = {10,6,7,12,367};
	printf("%d\n", solution.maximumGap(test));
	return 0;
}