/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int index = 0;

    TreeNode* solve(vector<int>& preorder, int minVal, int maxVal) {

        if (index >= preorder.size())
            return NULL;

        int val = preorder[index];

        if (val < minVal || val > maxVal)
            return NULL;

        TreeNode* root = new TreeNode(val);
        index++;

        root->left = solve(preorder, minVal, val);

        root->right = solve(preorder, val, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return solve(preorder, INT_MIN, INT_MAX);
    }
};