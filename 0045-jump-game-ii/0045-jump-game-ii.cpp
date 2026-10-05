class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        if(index >= nums.size() - 1)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int ans = INT_MAX;

        for(int jump = 1; jump <= nums[index]; jump++) {
            int next = solve(nums, index + jump, dp);

            if(next != INT_MAX)
                ans = min(ans, 1 + next);
        }

        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(nums, 0, dp);
    }
};