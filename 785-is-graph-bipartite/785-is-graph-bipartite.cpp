class Solution {
public:
    bool dfs(int i, vector<int> &colors, vector<vector<int>>& graph)
    {
        for(auto x : graph[i])
        {
            if(colors[x] == -1)
            {
                colors[x] = 1 - colors[i];
                if(dfs(x, colors, graph) == false)
                    return false;
            }
            else if(colors[x] == colors[i])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i=0; i<n; i++)
        {
            if(colors[i] == -1)
            {
                colors[i] = 1;
                if(dfs(i, colors, graph) == false)
                    return false;
            }
        }
        return true;
    }
};