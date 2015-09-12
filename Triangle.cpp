#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
    	for (int i = 1; i < triangle.size(); ++i) {
    		triangle[i][0] += triangle[i - 1][0];
    	}
    	for (int i = 1; i < triangle.size(); ++i) {
    		triangle[i][i] += triangle[i - 1][i - 1];
    	}
        for (int i = 1; i < triangle.size(); ++i) {
        	for (int j = 1; j < triangle[i].size() - 1; ++j) {
        		triangle[i][j] += (triangle[i - 1][j - 1] < triangle[i - 1][j] 
        				? triangle[i - 1][j - 1] : triangle[i - 1][j]);
        	}
        }
        int min = INT_MAX;
        for (int i = 0; i < triangle[triangle.size() - 1].size(); ++i) {
        	if (triangle[triangle.size() - 1][i] < min) {
        		min = triangle[triangle.size() - 1][i];
        	}
        }
        return min;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<vector<int> > triangle = {{2}};
	cout << solution.minimumTotal(triangle) << endl;
	return 0;
}