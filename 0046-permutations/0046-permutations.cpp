class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void solve(vector<int>& nums, vector<bool>& used) {

        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Choose
            used[i] = true;
            path.push_back(nums[i]);

            // Explore
            solve(nums, used);

            // Backtrack
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> used(nums.size(), false);

        solve(nums, used);

        return ans;
    }
};