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
    bool f(TreeNode * root, int sum, int target)
    {
        if(root == nullptr)
        {
            return false;
        }

        if(root->left == nullptr && root->right == nullptr)
        {
            if((sum + root->val) == target)
            {
                return true; 
            }
            return false;
        }
        bool left_ans = f(root->left,sum+root->val, target);
        bool right_ans = f(root->right,sum+root->val, target);
        return left_ans || right_ans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
                return f(root, 0, targetSum);
    }
};