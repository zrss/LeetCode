#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <iostream>

using namespace std;

// 利用两个数组
// 其中一个存储没有后继节点的节点，即为itinerary节点
// 另一个存储当前到达节点

// 图中有环
// 逆序思路，先考虑走完直线路径，再走环状路径
// 使用了multiset

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, multiset<string>> graph;
		for (auto pair : tickets) {
			graph[pair.first].insert(pair.second);
		}

		vector<string> arrive;
		vector<string> itinerary;

		arrive.push_back("JFK");

		while (!arrive.empty()) {
			string from = *arrive.rbegin();
			if (graph[from].size() > 0) { // 有后继
				arrive.push_back(*graph[from].begin());
				graph[from].erase(graph[from].begin());
			}
			else {
				itinerary.push_back(from); // 无后继
				arrive.pop_back();
			}
		}

		reverse(itinerary.begin(), itinerary.end());
		return itinerary;
	}
};

int main() {
	Solution solution;
	vector<pair<string, string>> tickets = { {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"} };
	vector<string> rel = solution.findItinerary(tickets);

	for (string itr : rel) {
		cout << itr << " ";
	}
	cout << endl;

	return 0;
}