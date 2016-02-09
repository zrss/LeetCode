#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	// first : in degree
    	// second : out degree
    	vector<pair<int, int>> degree(numCourses, pair<int, int>(0, 0));
    	vector<bool> end(numCourses, false);
    	vector<vector<int>> adj(numCourses, vector<int>());

    	for (auto itr : prerequisites) {
    		++(degree[itr.first].first);
    		++(degree[itr.second].second);
    		adj[itr.second].push_back(itr.first);
    	}

    	int endCnt = 0;
    	while (endCnt < numCourses) {
    		// 找到入度为0的节点
    		int inZero = 0;
    		for (; inZero < degree.size(); ++inZero) {
    			if (!end[inZero] && degree[inZero].first == 0) {
    				break;
    			}
    		}

    		if (inZero == degree.size()) {
    			return false;
    		}

    		// 减去当前节点带来的入度
    		for (auto itr : adj[inZero]) {
    			--degree[itr].first;
    		}

    		end[inZero] = true;
    		++endCnt;
    	}

    	return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<pair<int, int>> prerequisites = {{0, 1}, {3, 1}, {1, 3}, {3, 2}};
	cout << solution.canFinish(4, prerequisites) << endl;
	return 0;
}