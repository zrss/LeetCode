struct BiListNode {
    BiListNode() {};
	BiListNode(int key, int value):key(key), value(value) {};
	int key;
	int value;
	BiListNode* pre;
	BiListNode* next;
};

class BiList {
public:
	BiList():_count(0) {
		_head = new BiListNode();
		_head->pre = _head;
		_head->next = _head;
	}

	void push_front(BiListNode* pNode);

	void move_front(BiListNode* pNode);
    
    BiListNode* begin() {
        return _head->next;
    }
    
    BiListNode* rbegin() {
        return _head->pre;
    }
    
	void pop_back();

	int size() { return _count; }

	~BiList();

private:
	BiListNode* _head;
	int _count;
};

void BiList::push_front(BiListNode* pNode) {
	pNode->next = _head->next;
	pNode->pre = _head;
    _head->next->pre = pNode;
	_head->next = pNode;
	if (_head->pre == _head) {
		_head->pre = pNode;
	}
	++_count;
}

void BiList::move_front(BiListNode* pNode) {
	if (pNode == _head->next) {
		return;
	}
	pNode->pre->next = pNode->next;
	pNode->next->pre = pNode->pre;
	
    pNode->next = _head->next;
	pNode->pre = _head;
    
    _head->next->pre = pNode;
    
    _head->next = pNode;
}

void BiList::pop_back() {
	BiListNode* tailPtr = _head->pre;
	tailPtr->pre->next = _head;
	_head->pre = tailPtr->pre;
	delete tailPtr;
	--_count;
}

BiList::~BiList() {
	for (BiListNode* itr = _head->next; itr != _head; itr = itr->next) {
		delete itr;
	}
	delete _head;
}

struct hashNode {
    hashNode(int key, BiListNode* ptr):key(key), ptr(ptr), next(NULL) {};
    int key;
    BiListNode* ptr;
    hashNode* next;
};

class HashTable {
public:
    HashTable(int capacity);
    
    hashNode* find(int key);
    
    void insert(int key, BiListNode* ptr);
    
    void erase(int key);
    
    ~HashTable();
    
private:
    int _capacity;
    hashNode** hashArray;
};

HashTable::HashTable(int capacity):_capacity(capacity) {
    hashArray = new hashNode*[capacity];
    for (int i = 0; i < _capacity; ++i) {
        hashArray[i] = NULL;
    }
}

hashNode* HashTable::find(int key) {
    for (hashNode* itr = hashArray[key % _capacity]; itr != NULL;
            itr = itr->next) {
        if (itr->key == key) {
            return itr;
        }
    }
    return NULL;
}

void HashTable::insert(int key, BiListNode* ptr) {
    hashNode* tmp = new hashNode(key, ptr);
    
    int relativeKey = key % _capacity;
    
    if (hashArray[relativeKey] == NULL) {
        hashArray[relativeKey] = tmp;
        return;
    }

    tmp->next = hashArray[relativeKey];
    hashArray[relativeKey] = tmp;
}

void HashTable::erase(int key) {
    for (hashNode* pre = hashArray[key % _capacity], *itr = pre;
            itr != NULL; pre = itr, itr = itr->next) {
        if (itr->key == key) {
            if (itr != pre)
                pre->next = itr->next;
            else // head
                hashArray[key % _capacity] = itr->next;

            delete itr;
        }
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < _capacity; ++i) {
        for (hashNode* itr = hashArray[i]; itr != NULL;) {
            hashNode* tmp = itr;
            itr = itr->next;
            delete tmp;
        }
    }
    delete [] hashArray;
}

class LRUCache {
public:
    LRUCache(int capacity):_capacity(capacity) {
        hashTable = new HashTable(1024);
    };
    
    int get(int key);
    
    void set(int key, int value);
    
    ~LRUCache() { delete hashTable; }
    
private:
    int _capacity;
    BiList bilist;
    HashTable* hashTable;
};

int LRUCache::get(int key) {
    hashNode* tmp = hashTable->find(key);
    if (tmp != NULL) {
        bilist.move_front(tmp->ptr);
        return tmp->ptr->value;
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    hashNode* tmp = hashTable->find(key);
    if (tmp != NULL) { // set
        bilist.move_front(tmp->ptr);
        tmp->ptr->value = value;
        return;
    }
    
    // insert
    if (bilist.size() == _capacity) {
        hashTable->erase((bilist.rbegin())->key);
        bilist.pop_back();
    }

    bilist.push_front(new BiListNode(key, value));
    hashTable->insert(key, bilist.begin());
}