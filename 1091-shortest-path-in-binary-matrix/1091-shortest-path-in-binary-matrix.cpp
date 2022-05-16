class Solution {
public:
   
    bool check(int i,int j,map<pair<int,int>,bool>& visited,vector<vector<int>>& grid)
    {
        int n = grid.size();
        
        if(i >= 0 && j >= 0 && i < n && j < n && grid[i][j] != 1 && (visited.find({i,j}) == visited.end()))
        {
            return true;
        }
        
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
       
        queue<vector<int>> Q;
        Q.push({0,0,0}); // i,j,dist
        
        map<pair<int,int>,bool> visited;
        
        visited[{0,0}] = true;
        
        
        while(!Q.empty())
        {
            auto curr = Q.front();
            Q.pop();
            
            int i = curr[0],j = curr[1],dist = curr[2];
            
            if(i == n-1 && j == n-1)
            {
                return dist+1;
            }
            
            // left
            if(check(i,j-1,visited,grid))
            {
                visited[{i,j-1}] = true;
                Q.push({i,j-1,dist+1});
            }
            
            // right
            if(check(i,j+1,visited,grid))
            {
                visited[{i,j+1}] = true;
                Q.push({i,j+1,dist+1});
            }
            
            // up 
            if(check(i-1,j,visited,grid))
            {
                visited[{i-1,j}] = true;
                Q.push({i-1,j,dist+1});
            }
            
            // down 
            if(check(i+1,j,visited,grid))
            {
                visited[{i+1,j}] = true;
                Q.push({i+1,j,dist+1});
            }
            
            // leftUp
            if(check(i-1,j-1,visited,grid))
            {
                visited[{i-1,j-1}] = true;
                Q.push({i-1,j-1,dist+1});
            }
            
            // rightUp 
            if(check(i-1,j+1,visited,grid))
            {
                visited[{i-1,j+1}] = true;
                Q.push({i-1,j+1,dist+1});
            }
            
            // leftDown 
            if(check(i+1,j-1,visited,grid))
            {
                visited[{i+1,j-1}] = true;
                Q.push({i+1,j-1,dist+1});
            }
            
            // rightDown 
            if(check(i+1,j+1,visited,grid))
            {
                visited[{i+1,j+1}] = true;
                Q.push({i+1,j+1,dist+1});
            }
        }
        return -1;
    }
};