class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> answer(n, vector<int>(n,1));
        int stRow = 0, stCol = 0, endRow = n-1, endCol = n-1, count = n*n, a = 1;
        while(a <= count)
        {            
            //Starting Row
            for(int i=stCol; i <= endCol && a <= count; i++)
            {
                answer[stRow][i] = a;
                a++;
            }
            stRow++;
            //Endding Column
            for(int i=stRow; i <= endRow && a <= count; i++)
            {
                answer[i][endCol] = a;
                a++;
            }
            endCol--;
            //Ending Row
            for(int i=endCol; i >= stCol && a <= count; i--)
            {
                answer[endRow][i] = a;
                a++;
            }
            endRow--;
            //Starting column
            for(int i=endRow; i >= stRow && a <= count; i--)
            {
                answer[i][stCol] = a;
                a++;
            }
            stCol++;
        }
        return answer;
    }
};