class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto [key,value]:mp)
        {
            pq.push({value,key});
        }
        vector<int>ans;
        while(k--)
        {
            pair<int,int>p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};