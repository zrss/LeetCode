// easy problem

// 双指针

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isVowel(s[l])) {
                ++l;
            }

            while (l < r && !isVowel(s[r])) {
                --r;
            }

            swap(s[l++], s[r--]);
        }
        
        return s;
    }

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            || (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};