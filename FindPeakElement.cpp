#include <vector>
#include <iostream>

class Solution {
public:
    int findPeakElement(const std::vector<int> &num) {
    	if (num.size() == 1 || num[0] > num[1]) {
    		return 0;
    	}

    	if (*(num.rbegin()) > *(++num.rbegin())) {
    		return num.size() - 1;
    	}

        int l = 0;
        int u = num.size() - 1;

        while (l < u) {
        	int mid = (l + u) >> 1;
        	if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) {
        		return mid;
        	} else if (num[mid] > num[mid - 1]) {
        		l = mid + 1;
        	} else {
        		u = mid;
        	}
        }

        return l;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	std::vector<int> test = {1,2,3,1};
	std::cout << solution.findPeakElement(test) << std::endl;
	return 0;
}