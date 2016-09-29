#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	int cM[26];
    	memset(cM, 0, sizeof(cM));

    	for (int i = 0; i < magazine.length(); ++i) {
    		++cM[magazine[i] - 'a'];
    	}

    	bool rel = true;
    	for (int i = 0; rel && i < ransomNote.length(); ++i) {
    		if (cM[ransomNote[i] - 'a'] > 0) {
    			--cM[ransomNote[i] - 'a'];
    		} else {
    			rel = false;
    		}
    	}

    	return rel;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;

	return 0;
}