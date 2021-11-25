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
    bool isCousins(TreeNode* root, int x, int y) {
        map<int,pair<int,int>>m;
        
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->left && (temp->left->val==x || temp->left->val==y))  {
                    m[temp->left->val]={temp->val,level+1};
                }
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->right && (temp->right->val==x || temp->right->val==y)) {
                    q.push(temp->right);
                    m[temp->right->val]={temp->val,level+1};
                }            
            }
            level++;
        }
        if(m[x].first != m[y].first && m[x].second==m[y].second) return true;
        
        return false;
    }
};