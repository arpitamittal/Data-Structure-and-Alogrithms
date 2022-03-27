class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       priority_queue<pair<int, int>> pq;
        vector<int> answer;
        int i, n = mat.size();
        for(i=0; i< n; i++)
        {
            int count = 0;
            for(int j=0; j<mat[i].size(); j++)
            {
                if(mat[i][j] == 1)
                    count++;
            }
            pq.push({ count, i });
            while(pq.size() > k) pq.pop();
        }
        while(!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};