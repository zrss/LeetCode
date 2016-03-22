class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> strs = split(preorder);

        stack<string> stack;
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i] == "#") {
                if (stack.empty()) {
                    return i == (strs.size() - 1);
                }
                stack.pop();
            }
            else {
                stack.push(strs[i]);
            }
        }
        
        return false;
    }

    vector<string> split(const string& str) {
        stringstream ss(str);
        vector<string> res;
        string s;
        while (getline(ss, s, ',')) {
            res.push_back(s);
        }
        return res;
    }
};