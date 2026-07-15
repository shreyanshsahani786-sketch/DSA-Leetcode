class Solution {
public:

    vector<vector<int>> ans;
    vector<int> subset;

    void solve(vector<int>& nums, int index) {

        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Take
        subset.push_back(nums[index]);
        solve(nums, index + 1);

        // Backtrack
        subset.pop_back();

        // Don't Take
        solve(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(nums, 0);

        return ans;
    }
};