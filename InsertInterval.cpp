#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // intervalStart or gapStart
        int newStart = newInterval.start;
        int newEnd = newInterval.end;

        int intervalStart = -1;
        int gapStart = -1;

        for (int i = 0; i < intervals.size(); ++i) {
        	if (newStart < intervals[i].start) {
        		gapStart = i;
        		break;
        	} else if (newStart >= intervals[i].start && newStart <= intervals[i].end) {
        		intervalStart = i;
        		break;
        	}
        }

        // intervalEnd or gapEnd
        int intervalEnd = -1;
        int gapEnd = -1;

        for (int i = 0; i < intervals.size(); ++i) {
        	if (newEnd < intervals[i].start) {
        		gapEnd = i;
        		break;
        	} else if (newEnd >= intervals[i].start && newEnd <= intervals[i].end) {
        		intervalEnd = i;
        		break;
        	}
        }

        // can not find start then insert to tail
        if (intervalStart == -1 && gapStart == -1) {
        	gapStart = intervals.size();
        }

        // larger than end
        if (intervalEnd == -1 && gapEnd == -1) {
        	gapEnd = intervals.size();
        }

        // there comes conditions
        if (gapStart != -1 && gapEnd != -1) { // all in intervals gap
        	if (gapStart != gapEnd) {
        		intervals.erase(intervals.begin() + gapStart, intervals.begin() + gapEnd);
        	}
        	intervals.insert(intervals.begin() + gapStart, Interval(newStart, newEnd));
        	return intervals;
        }

        if (gapStart != -1) { // head in gap
        	Interval tmp(newStart, intervals[intervalEnd].end);
        	intervals.erase(intervals.begin() + gapStart, intervals.begin() + intervalEnd + 1);
        	intervals.insert(intervals.begin() + gapStart, tmp);

        	return intervals;
        }

        if (gapEnd != -1) { // tail in gap
        	Interval tmp(intervals[intervalStart].start, newEnd);
        	intervals.erase(intervals.begin() + intervalStart, intervals.begin() + gapEnd);
        	intervals.insert(intervals.begin() + intervalStart, tmp);

        	return intervals;
        }

        // all in inner intervals
        Interval tmp(intervals[intervalStart].start, intervals[intervalEnd].end);
        intervals.erase(intervals.begin() + intervalStart, intervals.begin() + intervalEnd + 1);
        intervals.insert(intervals.begin() + intervalStart, tmp);

        return intervals;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	Interval i1(1,5);
	Interval i2(6,10);
	vector<Interval> intervals = {i1, i2};

	Interval newInterval(11, 15);

	vector<Interval> rel = solution.insert(intervals, newInterval);

	for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
		cout << itr->start << " " << itr->end << endl;
	}
	return 0;
}