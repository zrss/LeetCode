#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int dv1 = version1.find('.');
        int dv2 = version2.find('.');

        int bv1 = trim(version1);
        int bv2 = trim(version2);

        if (dv1 == string::npos && dv2 == string::npos) {
        	return compare(version1, bv1, version1.length(), version2, bv2, version2.length());
        }
        if (dv1 != string::npos && dv2 != string::npos) {
        	int tmp = compare(version1, bv1, dv1, version2, bv2, dv2);
        	if (tmp == 0) {
        		tmp = compare(version1, dv1 + 1, version1.length(), version2, dv2 + 1, version2.length());
        	}
        	return tmp;
        }
        if (dv1 == string::npos) {
        	int tmp = compare(version1, bv1, version1.length(), version2, bv2, dv2);
        	if (tmp == 0) {
        		return -1;
        	}
        	return tmp;
        }
        int tmp = compare(version1, bv1, dv1, version2, bv2, version2.length());
        if (tmp == 0) {
        	return 1;
        }
        return tmp;
    }

    vector<string> split(string& target, char flag) {
    	vector<string> rel;
    	int pre = 0;
    	for (int i = 0; i < target.size(); ++i) {
    		if (target[i] == flag) {
    			if (pre != i - 1) {
    				rel.push_back(target.substr(pre, i));
    				pre = i + 1;
    			}
    		}
    	}

    }

    int trim(string& str) {
        int bv1 = 0;
        for (; str[bv1] == '0' && bv1 < str.length(); ++bv1) {
        }
        if (bv1 == str.length()) {
        	--bv1;
        }
        return bv1;
    }

    int compare(string& v1, int bv1, int ev1, string& v2, int bv2, int ev2) {
    	int c1 = ev1 - bv1;
    	int c2 = ev2 - bv2;

    	int gap = c1 - c2;

    	if (gap < 0) { // c2 > c1
    		return -1;
    	} else if (gap > 0) { // c1 > c2
    		return 1;
    	} else { // c1 == c2
    		for (int i = 0; i < c1; ++i) {
    			int tmp = v1[bv1++] - v2[bv2++];
    			if (tmp < 0) {
    				return -1;
    			} else if (tmp > 0) {
    				return 1;
    			}
    		}
    	}

    	return 0;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.compareVersion("010", "1") << endl;
	return 0;
}