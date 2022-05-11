class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator it;
    BrowserHistory(string homepage) 
    {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) 
    {
        auto del = it;
        del++;
        history.erase(del, history.end());
        history.push_back(url); 
        it++;
    }
    
    string back(int steps) 
    {
        while(steps > 0)
        {
            if(it == history.begin()) break;
            it--;
            steps--;
        }
        return *it;
    }
    
    string forward(int steps) 
    {
        auto last = --history.end();
        
        while(steps > 0)
        {
            if(it == last) break;
            it++;
            steps--;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 
  leetcode -> google -> facebook -> youtube -> linkedin 
               1            |
                             -> linkedin
 */