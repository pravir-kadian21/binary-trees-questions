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
    int ans=0;
    
    int helper(TreeNode *root){
        if(root==NULL) return 0;
        int lh = helper(root->left);
        int rh = helper(root->right);
        
        ans+=abs(lh-rh);
        return root->val+rh+lh;
    }
    
    int findTilt(TreeNode* root) {
        
        helper(root);
        return ans;
        
    }
};