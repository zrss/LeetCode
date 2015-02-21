#include <vector>
#include <cstdio>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int> > &dungeon) {
        // cal upperbound
        int M = dungeon.size();
        int N = dungeon[0].size();

        int lowerbound = 1;
        int upperbound = 1;

        // use right down path as upperbound
        int totalHP = 0;

        for (int c = 0; c < N; ++c) {
        	totalHP += dungeon[0][c];
        	if (totalHP < 0) {
        		upperbound -= totalHP;
                totalHP = 0;
        	}
        }

        for (int r = 1; r < M; ++r) {
            totalHP += dungeon[r][N - 1];
            if (totalHP < 0) {
                upperbound -= totalHP;
                totalHP = 0;
            }
        }

        if (upperbound == 1) {
            return 1;
        }
        
        const int MIN = -1000000;

        std::vector<std::vector<int>> curHP(M + 1, std::vector<int>(N + 1, MIN));

        // binary search between lowerbound and upperbound
        while (lowerbound < upperbound) {
            int mid = (lowerbound + upperbound) >> 1;

            curHP[1][0] = curHP[0][1] = mid;

            for (int r = 1; r <= M; ++r) {
                for (int c = 1; c <= N; ++c) {
                    int max = (curHP[r - 1][c] > curHP[r][c - 1] ?
                            curHP[r - 1][c] : curHP[r][c - 1]);

                    curHP[r][c] = max + dungeon[r - 1][c - 1];
                    
                    if (curHP[r][c] < 1) {
                        curHP[r][c] = MIN;
                    }
                }
            }

            if (curHP[M][N] < 0) {
                lowerbound = mid + 1;
            } else if (curHP[M][N] == 0) {
                return mid;
            } else {
                upperbound = mid;
            }            
        }

        return lowerbound;
    }
};


int main(int argc, char const *argv[])
{
	Solution solution;
	std::vector<std::vector<int>> test = {{3,-20,30},{-3,4,0}};
	printf("%d\n", solution.calculateMinimumHP(test));
	return 0;
}