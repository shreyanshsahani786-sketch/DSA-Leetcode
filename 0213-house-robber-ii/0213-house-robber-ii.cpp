class Solution {
public:

    int robLinear(vector<int>& nums, int start, int end)
    {
        int n = end - start + 1;

        if(n == 1)
            return nums[start];

        vector<int> dp(n);

        dp[0] = nums[start];

        dp[1] = max(nums[start], nums[start + 1]);

        for(int i = 2; i < n; i++)
        {
            int current = start + i;

            int take = nums[current] + dp[i - 2];

            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        // Case 1 exclude last
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2 exclude first
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};