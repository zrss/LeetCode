// simple recursion problem

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
    	cur = 0;
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger>& nestedList) {
    	for (int i = 0; i < nestedList.size(); ++i) {
    		if (nestedList[i].isInteger()) {
    			flatten_value.push_back(nestedList[i].getInteger());
    		} else {
    			flatten(nestedList[i].getList());
    		}
    	}
    }

    int next() {
        return flatten_value[cur++];
    }

    bool hasNext() {
        return cur < flatten_value.size();
    }

private:
	vector<int> flatten_value;
	int cur;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */