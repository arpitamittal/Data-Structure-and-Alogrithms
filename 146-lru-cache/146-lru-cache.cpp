class LRUCache {
public:
    int cap;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    list<int>dll;
    LRUCache(int capacity)
    {
     cap = capacity;
    }

    void moveToFirst(int key)
    {
     dll.erase(mp[key].first);
     dll.push_front(key);
     mp[key].first = dll.begin();
    }

    int get(int key) {
     if(mp.find(key) == mp.end()) return -1;
     moveToFirst(key);
     return mp[key].second;
    }

    void put(int key, int value) 
    {
     if(mp.find(key) == mp.end())
     {
      dll.push_front(key);
      mp[key] = {dll.begin(), value };
      cap--;
      if(cap < 0)
      {
          mp.erase(dll.back());
          dll.pop_back();
          cap++;
      }
    }       
     else
     {
      mp[key].second = value;
      moveToFirst(key);
     }     
    }
};