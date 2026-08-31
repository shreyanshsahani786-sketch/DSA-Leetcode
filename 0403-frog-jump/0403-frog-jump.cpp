class Solution {
public:

    bool solve(int i,
               int k,
               vector<int>& stones,
               unordered_map<int,int>& mp,
               vector<vector<int>>& dp)
    {
        int n = stones.size();

        if(i == n-1)
            return true;

        if(dp[i][k] != -1)
            return dp[i][k];

        for(int jump = k-1; jump <= k+1; jump++)
        {
            if(jump <= 0)
                continue;

            int nextPosition = stones[i] + jump;

            if(mp.find(nextPosition) != mp.end())
            {
                int nextIndex = mp[nextPosition];

                if(solve(nextIndex,
                         jump,
                         stones,
                         mp,
                         dp))
                {
                    return dp[i][k] = 1;
                }
            }
        }

        return dp[i][k] = 0;
    }

    bool canCross(vector<int>& stones)
    {
        int n = stones.size();

        if(n < 2 || stones[1] != 1)
            return false;

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[stones[i]] = i;
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return solve(1, 1, stones, mp, dp);
    }
};