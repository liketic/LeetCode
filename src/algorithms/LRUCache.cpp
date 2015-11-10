#include <iostream>
#include <string.h>

using namespace std;

//define a doubly linked list
struct CacheNode {
    int key;
    int value;
    CacheNode* prev;
    CacheNode* next;

    CacheNode(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};

struct TableNode {
    int key;
    CacheNode* listNode;
    TableNode* next;
    TableNode* prev;
    TableNode(int v, CacheNode* t): key(v), listNode(t), next(NULL), prev(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cacheSize = 0;
        this->capacity = capacity;
        hashTable = new TableNode*[capacity];
        for (int i = 0; i < capacity; i++) {
            hashTable[i] = new TableNode(0, NULL);
        }
        head = new CacheNode(0, 0);
        tail = new CacheNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        TableNode* t = getKeyNode(key);
        if (t) {
            moveListNodeToFront(t->listNode);
            return t->listNode->value;
        }
        return -1;
    }

    void set(int key, int value) {
        TableNode* t = getKeyNode(key);
        if (t) {
            t->listNode->value = value;
            moveListNodeToFront(t->listNode);
            return;
        }
        if (cacheSize == capacity) {
            removeLastNode();
            --cacheSize;
        }
        CacheNode* tt = addListNodeOnFront(key, value);
        ++cacheSize;
        addTableNode(tt);
    }

    void debugTable() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            if (hashTable[i]->next) {
                TableNode* current = hashTable[i]->next;
                while (current) {
                    cout << "(" << current->key << ","  << current->listNode->value << ")";
                    current = current->next;
                }
            }
            cout << endl;
        }
    }

    void debugList() {
        CacheNode* n = head;
        while (n) {
            cout << "(" << n->key << "," << n->value << ")";
            n = n->next;
        }
        cout << endl;
    }
private:
    TableNode** hashTable;
    CacheNode* head;
    CacheNode* tail;
    int cacheSize;
    int capacity;

    int hashKey(int key) {
        return (key % capacity);
    }

    void addTableNode(CacheNode* ln) {
        int k = hashKey(ln->key);
        TableNode* tn = hashTable[k];
        while (tn->next) {
            tn = tn->next;
        }
        TableNode* nodeToUse = new TableNode(ln->key, ln);
        tn->next = nodeToUse;
        nodeToUse->prev = tn;
    }

    void removeTableNode(int key) {
        TableNode* tn = getKeyNode(key);
        if (!tn) return;
        TableNode* prev = tn->prev;
        TableNode* next = tn->next;
        prev->next = next;
        if (next) {
            next->prev = prev;
        }
        delete tn;
        tn = NULL;
    }

    CacheNode* addListNodeOnFront(int key, int value) {
        CacheNode* nodeToUse = new CacheNode(key, value);
        addAfter(nodeToUse, head);
        return nodeToUse;
    }

    void removeLastNode() {
        removeTableNode(tail->prev->key);
        CacheNode* last = tail->prev;
        takeOut(last);
        delete last;
        last = NULL;
    }

    void takeOut(CacheNode* n) {
        CacheNode* prev = n->prev;
        CacheNode* next = n->next;
        prev->next = next;
        next->prev = prev;
    }

    void addAfter(CacheNode* n, CacheNode* tar) {
        CacheNode* after = tar->next;
        n->next = after;
        after->prev = n;
        tar->next = n;
        n->prev = tar;
    }

    void moveListNodeToFront(CacheNode* n) {
        takeOut(n);
        addAfter(n, head);
    }

    TableNode* getKeyNode(int key) {
        int k = hashKey(key);
        TableNode* n = hashTable[k]->next;
        while (n) {
            if (n->key == key) {
                return n;
            }
            n = n->next;
        }
        return NULL;
    }

};


int main() {

    LRUCache* c = new LRUCache(3);

    for (int i = 1; i <= 10; i++) {
        c->set(i, i);
        c->set(i + 3, i);
    }
    for (int i = 1; i <= 10; i++) {
        c->set(i, i);
    }
    for (int i = 1; i <= 100; i++) {
        cout << c->get(i) << endl;
    }

    return 0;
}

