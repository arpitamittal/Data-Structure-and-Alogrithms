class MyHashSet {
public:
    vector<list<int>> vec;
    int size;
    MyHashSet() 
    {
        size = 1000;
        vec.resize(size);
    }
    int hash(int key)
    {
        return key % size;
    }
    list<int> :: iterator search(int key)
    {
        int index = hash(key);
        return find(vec[index].begin(), vec[index].end(), key);
    }
    void add(int key) 
    {
        if(contains(key)) return;
        int index = hash(key);
        vec[index].push_back(key);
    }
    
    void remove(int key) 
    {
        if(!contains(key)) return;
        int index = hash(key);
        vec[index].erase(search(key)); 
    }
    
    bool contains(int key) 
    {
        int index = hash(key);
        if(search(key) != vec[index].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */