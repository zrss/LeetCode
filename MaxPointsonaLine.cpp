#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0) {
            return 0;
        }

        int max = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> map;

            int sameCount = 1;
            int infinite = 0;

            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++sameCount;
                } else if (points[i].x == points[j].x) {
                    ++infinite;
                } else {
                    double k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x); // ps: (double)
                    ++map[k];
                }
            }

            int tmp = sameCount + infinite;
            if (tmp > max) {
                max = tmp;
            }

            for (auto itr = map.begin(); itr != map.end(); ++itr) {
                int cur = (itr->second) + sameCount;
                if (cur > max) {
                    max = cur;
                }
            }
        }

        return max;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;

    Point p1(84, 250);
    Point p2(0, 0);
    Point p3(1, 0);
    Point p4(0, -70);
    Point p5(0, -70);
    Point p6(1, -1);
    Point p7(21, 10);
    Point p8(42, 90);
    Point p9(-42, -230);

    vector<Point> points = {p1, p2, p3, p4, p5, p6, p7, p8, p9};
    cout << solution.maxPoints(points) << endl;

	return 0;
}