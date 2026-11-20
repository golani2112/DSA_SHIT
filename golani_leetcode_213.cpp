class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp,int n)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int x=solve(nums,i+1,dp,n);
        int y=solve(nums,i+2,dp,n) + nums[i];
        return dp[i]=max(x,y);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans1=solve(nums,0,dp,n-1);
        if(n == 1) return nums[0];
        dp.assign(n + 1, -1);
        int ans2=solve(nums,1,dp,n);
        return max(ans1,ans2);
    }
};