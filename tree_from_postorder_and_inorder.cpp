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
    
    TreeNode *helper(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd,map<int,int>&m){

        if(inStart>inEnd || postStart>postEnd) return NULL;
        
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int idx = m[root->val];
        
        root->left = helper(inorder,postorder,inStart,idx-1,postStart,postStart+idx-inStart-1,m);
        
        root->right = helper(inorder,postorder,idx+1,inEnd,postStart+idx-inStart,postEnd-1,m);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m.insert({inorder[i],i});
        }
        
        TreeNode *root = helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,m);
        return root;
    }
};