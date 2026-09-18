class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current) {

        // Target complete
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Same level par duplicate skip
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array sorted hai
            // further elements bhi bade honge
            if (candidates[i] > target) {
                break;
            }

            // Choose
            current.push_back(candidates[i]);

            // Next index because same element reuse nahi karna
            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;

        backtrack(candidates, target, 0, current);

        return ans;
    }
};