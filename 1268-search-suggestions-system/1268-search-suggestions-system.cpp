class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string current = "";
        multiset<string> store;
        vector<string> temp;
        vector<vector<string>> ans;
        for(auto ch : searchWord)
        {
            current += ch;
            store.clear();
            for(auto it : products)
            {
                if(it.substr(0, current.length()) == current)
                    store.insert(it);
            }
            temp.clear();
            for(int i=0; i<3 and !store.empty(); i++)
            {
                temp.push_back(*store.begin());
                store.erase(store.begin());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};