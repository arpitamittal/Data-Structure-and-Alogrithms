class Solution {
public:
    void dfs(int i, vector<int> &index, vector<char> &letters, string &s, vector<vector<int>> &graphs, vector<bool> &visited)
    {
        visited[i] = true;
        index.push_back(i);
        letters.push_back(s[i]);
        for(int u : graphs[i])
        {
            if(!visited[u])
                dfs(u, index, letters, s, graphs, visited);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
       int n = s.size();
        vector<vector<int>> graph;
        vector<bool> visited;
       graph.resize(n);
        visited.resize(n,false);
        
        for(auto & x : pairs)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0; i<n; i++)
        {
            vector<int> index;
            vector<char> letters;
            if(!visited[i])
            {
                dfs(i, index, letters, s, graph, visited);
            }
            sort(index.begin(), index.end());
            sort(letters.begin(), letters.end());
            for(int i=0; i<index.size(); i++)
                s[index[i]] = letters[i];
        }
        return s;
    }
};