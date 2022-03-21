class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0), answer;
        for(int i=0; i<s.length(); i++) last[s[i]-'a'] = i;
        int start = 0, end = 0;
        for(int i=0; i<s.length(); i++)
        {
            end = max(end, last[s[i]-'a']);
            if(end == i)
            {
                answer.push_back(end - start + 1);
                start = i+1;
            }
        }
        return answer;
    }
};