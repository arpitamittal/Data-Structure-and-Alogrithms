class Solution {
public:
    bool isValid(int currRow, int currCol, int n,vector<vector<char>>& grid )
    {
        return isRowValid(currRow,n,grid) && isColValid(currCol,n,grid) && areDiagonalsValid(currRow,currCol,n,grid);
    }
    bool isRowValid(int currRow, int n, vector<vector<char>>& grid)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[currRow][j]=='Q')
                return false;
        }
        return true;
    }
     bool isColValid(int currCol, int n, vector<vector<char>>& grid)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[j][currCol]=='Q')
                return false;
        }
        return true;
    }
    bool areDiagonalsValid(int currRow, int currCol, int n, vector<vector<char>>& grid){
        int i= currRow;
        int j= currCol;
        while(i>=0 && j>=0)
        {
            if(grid[i][j]=='Q') 
                return false;
            i--;
            j--;
        }
        //return true;
        
         i= currRow;
         j= currCol;
        while(i>=0 && j<n)
        {
            if (grid[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        //return true;
        
        i= currRow;
        j= currCol;
        while(i<n && j>=0)
        {
            if (grid[i][j]=='Q') 
                return false;
            i++;
            j--;
        }
        //return true;
        
        i= currRow;
        j= currCol;
        while(i<n && j<n)
        {
            if (grid[i][j]=='Q') 
                return false;
            i++;
            j++;
        }
        return true;
    }
    vector<string> populate(vector<vector<char>>& grid, int n)
    {
        vector<string> vec;
        for(int currRow=0; currRow<n;currRow++)
        { 
            string temp = "";
            for(int currCol=0; currCol<n;currCol++)
            {
                temp += grid[currRow][currCol];
            }
            vec.push_back(temp);
        }
        return vec;
    }
    void nQueen(vector<vector<char>>& grid, int currRow, int n, vector<vector<string>> &answer){
        if(currRow==n)
        {
            vector<string>temp= populate(grid, n);
            answer.push_back(temp);
            return;
        }
        for(int currCol=0; currCol<n; currCol++)
        {
            if(isValid(currRow,currCol,n, grid))
            {
                grid[currRow][currCol] = 'Q';
                nQueen(grid, currRow+1, n, answer);
                grid[currRow][currCol] = '.';

            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        nQueen(grid, 0, n, answer);
        return answer;
    }
};