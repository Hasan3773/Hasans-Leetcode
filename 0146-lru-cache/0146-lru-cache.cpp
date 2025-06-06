#include <unordered_map>

struct Node {
    int key; 
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {} // constructor inializer list 
};

class LRUCache {
private:
    unordered_map<int,Node*> LRU;
    int maximum;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);


public:
    LRUCache(int capacity) {
        maximum = capacity;
        // head and tail in a linked list are their own nodes not just pointers lol 
        head->next = tail;
        tail->prev = head;
    }
    void remove(Node* node){
        node->prev->next = node->next; 
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }
    void add(Node* node){
        tail->prev->next = node; 
        node->prev = tail->prev;
        node->next = tail; 
        tail->prev = node;
    }
    int get(int key) {
        if (LRU.find(key) != LRU.end()){
            Node *node = LRU[key]; // node pointer to the node with this value in it
            // remove from wherever it is in the list
            // add to the end of the list 0 -> tail ---> 0 -> 0 -> tail
            Node* curr = head;
            remove(node);
            add(node);
            cout << "got: " << key << endl;
            return node->val;
        }
        return -1;
    }
    void put(int key, int value) {
        // key in the lru but updating value
        if (LRU.find(key) != LRU.end()){
            Node* curr = LRU[key];
            curr->val = value;
            remove(curr);
            add(curr);
        }
        // key not in the lru and there is space
        else if (LRU.size() < maximum){
            Node* curr = new Node(key,value);
            add(curr);
            LRU[key] = curr;
        }
        // lru full so we must delete node and insert new one 
        else{
            Node* dead = head->next;
            int deadKey = dead->key;
            remove(dead);
            LRU.erase(deadKey);
            Node* curr = new Node(key,value);
            add(curr);
            LRU[key] = curr;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */