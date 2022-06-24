class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<int> pq;
        long int sum =0;
        for(int x:t)
        {
            sum += x;
            pq.push(x);
        }
        while(sum>1 && pq.top() > sum/2)
        {
            int m = pq.top();
            sum-=m;
            if(sum<=1)
                return sum==0 ? false : true;
            m = m % (int)sum;
            pq.pop();
            pq.push(m);
            sum += m % sum;
        }
        return sum == t.size();
    }
};