#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool cmp(Point& pA, Point& pB) {
	if (pA.x != pB.x) {
		return pA.x < pB.x;
	}
	return pA.y < pB.y;
}

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 2) {
        	return 0;
        }
        if (points.size() == 2) {
        	return 1;
        }

        sort(points.begin(), points.end(), cmp);

        
    }

    bool inLine(Point& p1, Point& p2, Point& p3) {
    	return (p1.y - p2.y) * (p3.x - p2.x) == (p1.x - p2.x) * (p3.y - p2.y);
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	return 0;
}