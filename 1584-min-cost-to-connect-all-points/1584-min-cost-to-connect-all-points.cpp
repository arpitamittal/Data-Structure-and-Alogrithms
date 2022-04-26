class Solution {
public:
    int find(int u, vector<int> &parent)
    {
        if(parent[u] == u) return u;
        parent[u] = find(parent[u], parent);
        return parent[u];
    }
    bool union_(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int x = find(u, parent);
        int y = find(v, parent);
        if(x == y) return 0;
        if(rank[x] > rank[y]) parent[y] = x;
        else if(rank[y] > rank[x]) parent[x] = y;
        else
        {
            parent[x] = y;
            rank[y]++;
        }
        return 1;
    }
    static bool comp(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2)
    {
        return p1.first < p2.first;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> dist;
        int size = points.size();
        for(int i=0; i<size; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist.push_back({distance, {i,j}});
            }
        }
        sort(dist.begin(), dist.end(), comp);
        int ans = 0;
        vector<int> parent(size);
        for(int i=0; i<parent.size(); i++)
        {
            parent[i] = i;
        }
        vector<int> rank(parent.size(),0);
        int edgeUsed = 0;
        for(int i=0; i < dist.size() && edgeUsed < points.size()-1; i++)
        {
            bool result = union_(dist[i].second.first, dist[i].second.second, parent, rank);
            if(result)
            {
                ans += dist[i].first;
                edgeUsed++;
            }
        }
        return ans;
    }
};