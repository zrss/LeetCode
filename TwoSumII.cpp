#include <iostream>
#include <vector>

using namespace std;

// 双指针

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> rel = {1, numbers.size()};
        while (rel[0] < rel[1]) {
            int tmp = numbers[rel[0] - 1] + numbers[rel[1] - 1];
            if (tmp < target) {
                ++rel[0];
            } else if (tmp > target) {
                --rel[1];
            } else {
                return rel;
            }
        }
        return rel;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;

    return 0;
}