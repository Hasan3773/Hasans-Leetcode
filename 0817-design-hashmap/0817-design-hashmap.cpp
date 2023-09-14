class MyHashMap {
public:
    
    int SIZE;
    vector<list<pair<int,int>>>table;

    MyHashMap() {
        SIZE = 1000;
        table.resize(SIZE);
    }
    
    int hash(int key){
        return key % SIZE;
    }

    list<pair<int,int>>::iterator search(int key){
        int i = hash(key);

        list<pair<int,int>>::iterator itr = table[i].begin();
        while (itr != table[i].end()){
            if (itr->first == key)
                return itr;
            itr++;
        }
        return itr;
    }

    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        table[i].push_back(std::make_pair(key,value));
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int,int>>::iterator itr = search(key);
        if (itr == table[i].end())
            return -1;
        else
            return itr->second; 
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int,int>>::iterator itr = search(key);
        if (itr != table[i].end())
            table[i].erase(itr);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */