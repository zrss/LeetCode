// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums), have_cur(false) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!have_cur) {
            cur_integer = Iterator::next();
            have_cur = true;
        }
        return cur_integer;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (have_cur) {
            have_cur = false;
            return cur_integer;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        return have_cur || Iterator::hasNext();
    }

    bool have_cur;
    int cur_integer;
};