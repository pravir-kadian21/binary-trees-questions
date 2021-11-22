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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=1;
        while(!q.empty()){
            int size = q.size();
            int mini,maxi;
            for(int i=0;i<size;i++){
                pair temp = q.front();
                q.pop();
                if(i==0){
                    mini=temp.second;
                }
                if(i==size-1){
                    maxi = temp.second;
                    ans = max(ans,maxi-mini+1);
                }
                if(temp.first->left){
                    q.push({temp.first->left,2*(temp.second-mini)+1});
                }
                if(temp.first->right){
                    q.push({temp.first->right,2*(temp.second-mini)+2});
                }
            }
        }
        return ans;
    }
};