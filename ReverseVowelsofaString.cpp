// easy problem
// use vIndex to store the index of vowels
// then use two pointers to reverse vIndex and corresponding string s real index

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vIndex;
        
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case 'a':case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':
                    vIndex.push_back(i);
                break;
            }
        }
        
        // [sPtr, ePtr]
        int sPtr = 0;
        int ePtr = (int)vIndex.size() - 1;
        
        while (sPtr < ePtr) {
            swap(s[vIndex[sPtr]], s[vIndex[ePtr]]);
            ++sPtr;
            --ePtr;
        }
        
        return s;
    }
};