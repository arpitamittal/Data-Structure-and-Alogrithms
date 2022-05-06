class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        
        for(int i=0;i<s.size();i++)
        {
            if(s.size()==0)
            {
                ans.push_back(s[i]);
            }
            
            else if(s[i]!=ans.back())
            {
                ans.push_back(s[i]);
            }
            else
            {
                ans.pop_back();
            }
        }
        
        return ans;
    }
};