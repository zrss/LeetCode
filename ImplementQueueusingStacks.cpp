#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        pushStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        popStack.pop();
    }

    // Get the front element.
    int peek(void) {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        return popStack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return pushStack.empty() && popStack.empty();
    }

private:
    stack<int> pushStack;
    stack<int> popStack;
};

int main(int argc, char const *argv[])
{
    Queue queue;
    queue.push(1);

    cout << queue.peek() << endl;

    return 0;
}