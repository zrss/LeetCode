class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        stack.push(s[0]);
        
        int next = 1;
        bool cont = true;
        
        while (cont && next < s.length()) {
            switch (s[next]) {
                case '(': case '{': case '[':
                stack.push(s[next]);
                break;
                case ')':
                cont = match(stack, '(');
                break;
                case '}':
                cont = match(stack, '{');
                break;
                case ']':
                cont = match(stack, '[');
                break;
            }
            ++next;
        }
        
        return stack.empty() && cont;
    }
    
    // ch == ( , { , [
    bool match(stack<char>& stack, char ch) {
        if (stack.empty() || stack.top() != ch) {
            return false;
        }
        
        stack.pop();
        return true;
    }
};