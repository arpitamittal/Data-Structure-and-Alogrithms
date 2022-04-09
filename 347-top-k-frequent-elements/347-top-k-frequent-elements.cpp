class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        priority_queue<pair<int, int>> pq;
        for(auto x : mp)
        {
            pq.push({-1*x.second, x.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> answer;
        while(!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};