class Solution {
public:

    int solve(int i, vector<int>& nums,vector<int>& dp)
    {
        if(i==0)
            return nums[0];

        if(i<0)
            return 0;

        if(dp[i]!=-1)
        return dp[i];

        int inclu = nums[i] + solve(i-2, nums, dp);

        int exclu = solve(i-1, nums, dp);

        dp[i]= max(inclu, exclu);

        return dp[i];
    }

    int rob(vector<int>& nums)
    {

        int i =nums.size();
        vector<int>dp(i,-1);
        return solve(i-1, nums, dp);
    }
};