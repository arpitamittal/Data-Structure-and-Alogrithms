class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int i;
        priority_queue<int> q;
        for(i=0; i<heights.size()-1; i++)
        {
            if(heights[i+1] <= heights[i])
                continue;
            int depth = heights[i+1] - heights[i];
            if(depth <= bricks)
            {
                bricks -= depth;
                q.push(depth);
            }
            else if(ladders > 0)
            {
                if(q.size())
                {
                    int x = q.top();
                    if(x > depth)
                    {
                        bricks += x;
                        q.pop();
                        q.push(depth);
                        bricks -= depth;
                    }              
                }
                ladders--;  
            }
            else break;
        }
        return i;
    }
};