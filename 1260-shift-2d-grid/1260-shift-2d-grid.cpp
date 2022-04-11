class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> answer(n, vector<int>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int newCol = (j + k) % m;
                int newRow = (i +(j + k) / m) % n;
                answer[newRow][newCol] = grid[i][j];
            }
        }
        return answer;
    }
};