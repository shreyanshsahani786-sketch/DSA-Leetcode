class Solution {
public:

    int solve(vector<int>& nums, int i, int end, vector<int>& dp)
    {
        if(i > end)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(nums, i + 2, end, dp);

        int notTake = solve(nums, i + 1, end, dp);

        return dp[i] = max(take, notTake);
    } 
    int rob(vector<int>& nums) {

         int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n, -1);

        // Case 1
        int case1 = solve(nums, 0, n - 2, dp);

        // Reset dp for second case
        fill(dp.begin(), dp.end(), -1);

        // Case 2
        int case2 = solve(nums, 1, n - 1, dp);

        return max(case1, case2);
    }
};