#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval& a, Interval& b) {
	if (a.start != b.start) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

bool myequal(Interval& a, Interval& b) {
	return a.start == b.start && a.end == b.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	sort(intervals.begin(), intervals.end(), cmp);
    	intervals.erase(unique(intervals.begin(), intervals.end(), myequal), intervals.end());

    	vector<Interval> rel;
    	int cnt = intervals.size();
        int i = 0;

    	while (i < cnt - 1) {
            if (intervals[i].end < intervals[i + 1].start) {
                rel.push_back(intervals[i]);
                ++i;
            } else {
                // cal new end
                int nItr = i + 1;
                int curEnd = intervals[i].end;

                while (nItr < cnt && curEnd >= intervals[nItr].start) {
                    while (nItr < cnt && curEnd >= intervals[nItr].start) {
                        if (curEnd < intervals[nItr].end) {
                            curEnd = intervals[nItr].end;
                        }
                        ++nItr;
                    }

                    if (curEnd <= intervals[nItr - 1].end) {
                        curEnd = intervals[nItr - 1].end;
                    }
                }

                rel.push_back(Interval(intervals[i].start, curEnd));
                i = nItr;
            }
        }

        if (i == cnt - 1) {
            rel.push_back(intervals[i]);
        }

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Interval i1(1,4);
	Interval i2(1,5);
	Interval i3(3,5);
	Interval i4(15,18);

	vector<Interval> intervals = {i1, i2, i3, i4};

	Solution solution;
	vector<Interval> rel = solution.merge(intervals);

	for (Interval interval : rel) {
		cout << interval.start << " " << interval.end << endl;
	}
	return 0;
}