class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void solve(vector<int>& candidates, int target, int index) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // Take current element
        path.push_back(candidates[index]);

        solve(candidates, target - candidates[index], index);

        // Backtrack
        path.pop_back();

        // Skip current element
        solve(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        solve(candidates, target, 0);

        return ans;
    }
};