#include <iostream>
#include <vector>

using namespace std;

// 枚举的思路
// 0 的情况需要注意

// 100
// 200
// 是不符合条件的

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<bool> visited(10, false);
        int cnt = 0;
        
        // 一位不重复的数字
        // 两位不重复的数字
        // ...
        for (int i = 1; i <= n; ++i) {
            aux(i, 0, visited, cnt);
        }

        // 加上没有统计的0
        return cnt + 1;
    }

    // 遍历每一位的情况
    // 注意0不能在开头
    void aux(int pos_num, int cur_num, vector<bool>& visited, int& cnt) {
        if (cur_num == pos_num) {
            ++cnt;
            return;
        }

        for (int i = (cur_num + 1) != pos_num ? 0 : 1; i < 10; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                aux(pos_num, cur_num + 1, visited, cnt);
                visited[i] = false;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.countNumbersWithUniqueDigits(3) << endl;
    return 0;
}