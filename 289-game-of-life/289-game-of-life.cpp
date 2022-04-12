class Solution {
public:
    int liveNeighbours(vector<vector<int>> & curr, int i, int j, int m, int n)
    {
        int neighbours=0;
	// Upper
	  if(i > 0) 
        {
            if(curr[i-1][j] == 1) 
                neighbours++;
        }
        //Lower
        if(i < m-1)
        {
            if(curr[i+1][j] == 1)
                neighbours++;
        }
        //Left
        if(j > 0)
        {
            if(curr[i][j-1] == 1)
                neighbours++;
        }
        //Right
        if(j < n-1)
        {
            if(curr[i][j+1] == 1)
                neighbours++;
        }
         
        //Upper Left Diagonal
        if(i > 0 && j > 0)
        {
            if(curr[i-1][j-1] == 1)
                neighbours++;
        }
        //Upper Right Diagonal
        if(i > 0 && j < n-1)
        {
            if(curr[i-1][j+1] == 1)                      
                neighbours++;
        }
        //Lower Left Diagonal
        if(i < m-1 && j > 0)
        {
            if(curr[i+1][j-1] == 1)                
                neighbours++;
        }
        //Lower Right Diagonal
        if(i < m-1 && j < n-1)
        {
            if(curr[i+1][j+1] == 1)                 
                neighbours++;
        }
        return neighbours;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> curr = board;
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int ans = liveNeighbours(curr, i, j, m, n);
                if(board[i][j] == 0)
                {
                    if(ans == 3)
                        board[i][j] = 1;
                }
                else if(board[i][j] == 1)
                {
                    if(ans < 2 || ans > 3)
                        board[i][j] = 0;
                }
            }
        }
        
    }

};