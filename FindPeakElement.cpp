#include <vector>
#include <iostream>

class Solution {
public:
    int findPeakElement(const std::vector<int> &num) {
        if (num.size() == 1) {
        	return 0;
        }

        if (num[0] > num[1]) {
        	return 0;
        }

        if (*(num.rbegin()) > *(++num.rbegin())) {
        	return num.size() - 1;
        }


        int count = num.size() - 1;
        for (int i = 1; i < count; ++i) {
        	if (num[i] > num[i - 1] && num[i] > num[i + 1]) {
        		return i;
        	}
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	std::vector<int> test = {1,2,3,1};
	std::cout << solution.findPeakElement(test) << std::endl;
	return 0;
}