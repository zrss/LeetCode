#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        popQueue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        locateFront();
        popQueue.pop();
    }

    // Get the top element.
    int top() {
        locateFront();
        return popQueue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return popQueue.empty() && pushQueue.empty();
    }

    void locateFront() {
        if (popQueue.empty()) {
        	while (!pushQueue.empty()) {
        		popQueue.push(pushQueue.front());
        		pushQueue.pop();
        	}
        }

    	while (popQueue.size() > 1) {
    		pushQueue.push(popQueue.front());
    		popQueue.pop();
    	}
    }
private:
	queue<int> popQueue;
	queue<int> pushQueue;
};

int main(int argc, char const *argv[]) {
	Stack stack;
	stack.push(1);
	cout << stack.top() << endl;
	return 0;
}