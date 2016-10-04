#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cctype>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;

	return p1.first > p2.first;
}

// 参考的思路
// 自己手写嗯

// 首先按高度降序排序，若高度相同，再按人数升序排序
// 从左到右遍历排序后的数组
// 人数即为元素所在数组中的位置，不断做插入即可

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), cmp);

		list<pair<int, int>> peopleList(people.begin(), people.end());
		for (list<pair<int, int>>::iterator itr = peopleList.begin(); itr != peopleList.end(); ) {
			
			list<pair<int, int>>::iterator start = peopleList.begin();
			
			// find position to insert
			int cnt = 0;
			int len = itr->second;
			while (cnt < len) {
				++start;
				++cnt;
			}
			
			if (start != itr) {
				pair<int, int> node = *itr;
				itr = peopleList.erase(itr);
				peopleList.insert(start, node);
			}
			else {
				++itr;
			}
		}

		vector<pair<int, int>> result;
		for (list<pair<int, int>>::iterator itr = peopleList.begin(); itr != peopleList.end(); ++itr) {
			result.push_back(*itr);
		}

		return result;
	}
};

int main() {
	vector<pair<int, int>> people = { {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2} };
	vector<pair<int, int >> result = Solution().reconstructQueue(people);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i].first << " " << result[i].second << endl;
	}
	return 0;
}