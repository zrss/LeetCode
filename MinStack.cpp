class MinStack {
public:
    void push(int x) {
        if (store.empty() || x < min) { // 注意顺序
            min = x;
        }
        store.push_back(x);
    }

    void pop() { // 注意顺序
        int tmpTop = top();
        store.pop_back();
        if (tmpTop == min) {
            updateMin();
        }
    }

    int top() {
        return *(store.rbegin());
    }

    int getMin() {
        return min;
    }
    
private:
    vector<int> store;
    bool init = true;
    bool update = false;
    int min = INT_MAX;
    
    void updateMin() {
        if (store.size() > 0) {
            int tmpMin = store[0];
            for (int i = 1; i < store.size(); ++i) {
                if (store[i] < tmpMin) {
                    tmpMin = store[i];
                }
            }
            min = tmpMin;
        }
    }
};