class MyHashMap {
public:
    vector<list<pair<int, int>>> li;
    int size;
    MyHashMap() 
    {
        size = 1e6;
        li.resize(size);
    }
    int hash(int key)
    {
        return key % size;
    }
    list<pair<int, int>> :: iterator search(int key)
    {
        int idx = hash(key);
        list<pair<int, int>> :: iterator it = li[idx].begin();
        while(it != li[idx].end())
        {
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    void put(int key, int value) 
    {
        int idx = hash(key);
        remove(key);
        li[idx].push_back({key, value});
    }
    
    int get(int key) 
    {
        int idx = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it == li[idx].end()) return -1;
        else return it->second;
    }
    
    void remove(int key) 
    {
        int idx = hash(key);
        auto it = search(key);
        if(it != li[idx].end()) li[idx].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */