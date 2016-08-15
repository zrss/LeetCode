#include <iostream>
#include <string>
#include <vector>

using namespace std;

// naive解法
// 调试还麻烦

class Solution {
public:
    string simplifyPath(string path) {
    	path += "/";

        int dot_cnt = 0;
        vector<int> path_start;
        bool first_meet = true;

        len = path.length();

        for (int i = 0; i < len; ++i) {
        	switch (path[i]) {
        		case '.':
        		++dot_cnt;
        		break;
        		case '/':
        		if (dot_cnt == 1) {
        			moveForward(path, i - 1, i + 1);
        			i -= 2;
        		} else if (dot_cnt == 2) {
        			cout << "i: " << i << endl;
        			if (!path_start.empty()) {
	        			moveForward(path, *path_start.rbegin(), i + 1);
	        			i = *path_start.rbegin() - 1;
	        			path_start.pop_back();
        			} else if (path[0] == '/') {
        				moveForward(path, 0, i);
        				i = 0;
        			}
        		} else if (i > 0 && path[i - 1] == '/') {
        			moveForward(path, i - 1, i);
        			--i;
        		}
        		dot_cnt = 0;
        		first_meet = true;
        		break;
        		default:
        		if (dot_cnt == 1) {
        			path_start.push_back(i - 1);
        			first_meet = false;
        		} else {
	        		if (first_meet) {
	        			path_start.push_back(i);
	        			first_meet = false;
	        		}
        		}

        		dot_cnt = 0;
        		break;
        	}
        }

        cout << len << endl;

        if (len > 1 && path[len - 1] == '/') {
        	--len;
        }

        return string(path.begin(), path.begin() + len);
    }

    void moveForward(string& path, int s, int t) {
    	while (t < len) {
    		swap(path[s++], path[t++]);
    	}
    	len = s;
    }

private:
	int len;
};

int main(int argc, char const *argv[]) {
	Solution solution;
	cout << solution.simplifyPath("/home") << endl;
	return 0;
}