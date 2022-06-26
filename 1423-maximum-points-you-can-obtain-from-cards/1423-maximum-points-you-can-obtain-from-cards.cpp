class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n=cardPoints.size();
        int totalScore=0;
        int startingIndex = 0;
        int presentSubarrayScore = 0; 
        
        for(auto e : cardPoints)
            totalScore+= e;
        
        if (k == n)
            return totalScore;
        
        int minSubArrayScore = totalScore;
        
        for(int i=0; i<n; i++) 
        {
            presentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startingIndex + 1;
            if(presentSubarrayLength == n-k) 
            {
                minSubArrayScore = min(minSubArrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex++];
            }
        }
        return totalScore-minSubArrayScore;
    }
};