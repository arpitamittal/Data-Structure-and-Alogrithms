class MyHashMap {
public:
    vector<int> li;
    int size;
    MyHashMap() 
    {
        size = 1e6 + 1;
        li.resize(size);
        fill(li.begin(), li.end(), -1);
    }
    
    void put(int key, int value) 
    {
        li[key] = value;
    }
    
    int get(int key) 
    {
        return li[key];
    }
    
    void remove(int key) 
    {
        li[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */