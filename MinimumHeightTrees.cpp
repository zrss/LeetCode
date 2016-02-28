#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	// 拓扑排序

    	// 度统计
    	vector<int> degree(n, 0);

    	// 邻接表
    	vector<unordered_set<int>> linkTable(n, unordered_set<int>());
    	for (auto pair : edges) {
    		linkTable[pair.first].insert(pair.second);
    		linkTable[pair.second].insert(pair.first);

    		++degree[pair.first];
    		++degree[pair.second];
    	}

    	int cnt = n;

    	while (cnt > 2) {
    		vector<int> record;
    		for (int i = 0; i < n; ++i) {
    			if (degree[i] == 1) {
    				record.push_back(i);
    				degree[i] = -1;
    				--cnt;
    			}
    		}

			// 更新度统计
			for (auto each : record) {
				for (auto deg : linkTable[each]) {
					--degree[deg];
				}
			}
    	}

    	// 度为1或者0的都是结果
    	vector<int> rel;
    	for (int i = 0; i < degree.size(); ++i) {
    		if (degree[i] == 1 || degree[i] == 0) {
    			rel.push_back(i);
    		}
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}