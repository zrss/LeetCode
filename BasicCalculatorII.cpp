#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 写的比较复杂
// 主要是在判断运算符优先级上
// 使用了两个栈分别存储运算符和操作数

class Solution {
public:
    int calculate(string s) {
    	stack<int> num_stack;
    	stack<char> op_stack;

    	int num = 0;
    	for (int i = 0; i < s.length(); ++i) {
    		if (s[i] == ' ') {
    			continue;
    		}
    		if (isNumber(s[i])) {
    			num *= 10;
    			num += (s[i] - '0');
    		} else {
    			num_stack.push(num);
                num = 0;

                // 足够的操作数，判断是否进行运算
                if (num_stack.size() >= 2) {
                    if (s[i] == '+' || s[i] == '-') { // 当前为加减操作，则之前操作可以执行
                        while (num_stack.size() >= 2) {
                            int n2 = num_stack.top();
                            num_stack.pop();
                            int n1 = num_stack.top();
                            num_stack.pop();

                            switch (op_stack.top()) {
                                case '+':
                                num_stack.push(n1 + n2);
                                break;
                                case '-':
                                num_stack.push(n1 - n2);
                                break;
                                case '*':
                                num_stack.push(n1 * n2);
                                break;
                                case '/':
                                num_stack.push(n1 / n2);
                                break;
                            }

                            op_stack.pop();
                        }
                    } else { 
                        while (num_stack.size() >= 2 && (op_stack.top() == '*' || op_stack.top() == '/')) { // 当前操作为乘除，则之前操作为乘除时可以执行
                            int n2 = num_stack.top();
                            num_stack.pop();
                            int n1 = num_stack.top();
                            num_stack.pop();

                            if (op_stack.top() == '*') {
                                num_stack.push(n1 * n2);
                            } else {
                                num_stack.push(n1 / n2);
                            }

                            op_stack.pop();
                        }
                    }
                }

                // 操作符入栈
                op_stack.push(s[i]);
    		}
    	}

        num_stack.push(num);

        // 计算剩余的操作
        while (!op_stack.empty()) {
            int n2 = num_stack.top();
            num_stack.pop();
            int n1 = num_stack.top();
            num_stack.pop();

            switch (op_stack.top()) {
                case '+':
                num_stack.push(n1 + n2);
                break;
                case '-':
                num_stack.push(n1 - n2);
                break;
                case '*':
                num_stack.push(n1 * n2);
                break;
                case '/':
                num_stack.push(n1 / n2);
                break;
            }

            op_stack.pop();
        }

        return num_stack.top();
    }

    bool isNumber(char ch) {
    	return (ch >= '0' && ch <= '9');
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	string s = "1*2-3/4+5*6-7*8";
	cout << solution.calculate(s) << endl;
	return 0;
}