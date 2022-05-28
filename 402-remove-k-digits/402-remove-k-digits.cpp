class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        string ans = "";
        if(n < k) return "0";
        s.push(num[0]);
        for(int i=1; i<num.size(); i++)
        {
           while(k > 0 && !s.empty() && num[i] < s.top())
           {
               --k;
               s.pop();
           }
            s.push(num[i]);
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        while(k && !s.empty())
        {
            --k;
            s.pop();
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        if(ans.size() == 0) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};