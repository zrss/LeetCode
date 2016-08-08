#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int SIZE = 4096;

struct HashNode {
    int val;

    HashNode(): val(0), next(NULL) {}
    HashNode(int v): val(v), next(NULL) {}

    HashNode* next;
};

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet(): keyNum(0) {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int hashVal = hashCode(val);

        HashNode* cur = &array[hashVal];
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                return false;
            }
            cur = cur->next;
        }

        cur->next = new HashNode(val);
        ++keyNum;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int hashVal = hashCode(val);

        HashNode* cur = &array[hashVal];
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                HashNode* target = cur->next;
                cur->next = cur->next->next;
                --keyNum;
                delete target;
                return true;
            }
        }

        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (keyNum == 0) {
            return 0;
        }

        int hashVal = 0;
        do {
            hashVal = rand() % SIZE;
        } while (array[hashVal].next == NULL);

        // list len
        int len = 0;
        HashNode* cur = array[hashVal].next;
        while (cur != NULL) {
            ++len;
            cur = cur->next;
        }

        int pos = rand() % len;
        int cnt = 0;
        cur = array[hashVal].next;
        while (cnt < pos) {
            ++cnt;
            cur = cur->next;
        }

        return cur->val;
    }

    int hashCode(int val) {
        return val & (SIZE - 1);
    }

/*    ~RandomizedSet() {
        for (int i = 0; i < SIZE; ++i) {
            HashList& hashList = array[i];
            HashNode* cur = &hashList.vHead;
            while (cur != NULL) {
                HashNode* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }
    }*/

private:
    int keyNum;
    HashNode array[SIZE];
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

 int main(int argc, char const *argv[]) {
     RandomizedSet randomizedSet;
     randomizedSet.insert(1);
     randomizedSet.remove(2);
     randomizedSet.insert(2);
     randomizedSet.remove(1);
     randomizedSet.insert(2);
     cout << randomizedSet.getRandom() << endl;
     return 0;
 }