#include <iostream>
#include <vector>
#include <string>

using namespace std;

// KMP

class Solution {
public:
    int strStr(string haystack, string needle) {
    	int i = 0; // s
    	int j = 0; // p

        if (needle.length() == 0) {
            return 0;
        }

        if (haystack.length() == 0) {
            return -1;
        }

        int* next = getNext(needle);

        int nL = needle.length(); // unsigned int to int
        // !ps else j < needle.length() when j = -1 is always false

    	while (i < haystack.length() && j < nL) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }

        delete [] next;

        if (j == nL) {
            return i - j;
        }

        return -1;
    }

private:
    // P[0] ... P[next[k]] ... P[k - 1] P[k]
    // P[j - k] ... P[j - 1] P[j]
    // if P[k] != P[j]
    // then match P[next[k]] and P[j]
    // as P[0] ... P[next[k] - 1] equal to P[j - next[k]] ... P[j - 1]
    int* getNext(string& p) {
    	int k = -1;
    	int j = 0;

        int* next = new int[p.length()];
        next[0] = -1;

        int pE = p.length() - 1; // !ps p.length() array out of index

    	while (j < pE) {
    		if (k == -1 || p[k] == p[j]) {
    			++k;
    			++j;
    			next[j] = k;
    		} else {
    			k = next[k];
    		}
    	}

        return next;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
    cout << solution.strStr("mississippi", "issipi") << endl;
	return 0;
}