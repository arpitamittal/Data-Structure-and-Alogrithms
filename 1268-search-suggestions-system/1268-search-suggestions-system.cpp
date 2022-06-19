class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string current = "";
        vector<string> temp;
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        for(auto ch : searchWord)
        {
            current += ch;
            temp.clear();
            for(auto it : products)
            {
                if(it.substr(0, current.length()) == current)
                    temp.push_back(it);
                if(temp.size() == 3)
                    break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};