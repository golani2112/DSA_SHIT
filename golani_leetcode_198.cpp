class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int x=solve(nums,i+1,dp);
        int y=solve(nums,i+2,dp) + nums[i];
        return dp[i]=max(x,y);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=solve(nums,0,dp);
        vector<int>dp2(n,-1);
        int ans2=solve(nums,1,dp2);
        return max(ans,ans2);
    }
};