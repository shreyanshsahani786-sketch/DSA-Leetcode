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

string ans = "";

void dfs(TreeNode* root, string &curr)
{
    if(root == NULL)
        return;

    curr.push_back(root->val + 'a');

    // Leaf Node
    if(root->left == NULL &&
       root->right == NULL)
    {
        string temp = curr;

        reverse(temp.begin(), temp.end());

        if(ans == "" || temp < ans)
            ans = temp;
    }

    dfs(root->left, curr);
    dfs(root->right, curr);

    // Backtracking
    curr.pop_back();
}

string smallestFromLeaf(TreeNode* root)
{
    string curr = "";

    dfs(root, curr);

    return ans;
}
};