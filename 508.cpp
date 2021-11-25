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
    
    unordered_map<int,int>m;
    
    int helper(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int l=helper(root->left);
        int r = helper(root->right);
        
        if(m.find(l+r+root->val)!=m.end()){
            m[l+r+root->val]+=1;
        }
        else{
            m[l+r+root->val]=1;
        }
        return l+r+root->val;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int>ans1;
        vector<int>ans2;
        int maxi=1;
        for(auto &it:m){
            if(it.second>maxi){
                maxi = it.second;
                
            }
        }
        vector<int>ans;
        for(auto &it:m){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;   
    }
};