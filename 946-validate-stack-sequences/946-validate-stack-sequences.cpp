class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        stack<int> s;
        while(i < pushed.size())
        {
            s.push(pushed[i]);
            while(s.size() > 0 and popped[j] == s.top())
            {
                s.pop();
                j++;
            }
            i++;
        }
        return i == pushed.size() && j == popped.size();
    }
};