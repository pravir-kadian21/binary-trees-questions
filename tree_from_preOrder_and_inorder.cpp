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
    
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>&m){
        if(inStart>inEnd || preStart>preEnd){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int idx = m[root->val];
        
        root->left = helper(preorder,inorder,preStart+1,preStart+idx-inStart,inStart,idx-1,m);
        root->right = helper(preorder,inorder,preStart+idx-inStart+1,preEnd,idx+1,inEnd,m);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m.insert({inorder[i],i});
        }
        TreeNode *root = helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,m);
        return root;
    }
};