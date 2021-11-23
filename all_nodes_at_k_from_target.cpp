/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void parent(TreeNode *root,map<TreeNode*,TreeNode*>&m){
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    m.insert({temp->left,temp});
                }
                if(temp->right){
                    q.push(temp->right);
                    m.insert({temp->right,temp});
                }
            }
        }
    }
    
    bool visited(TreeNode*root,vector<TreeNode*>&visi){
        auto it = find(visi.begin(),visi.end(),root);
        if(it!=visi.end()) return true;
        
        return false;
    }
    
    void helper(TreeNode *target,int k,vector<int>&ans,map<TreeNode*,TreeNode*>&m){
        
        queue<TreeNode*>q;
        q.push(target);
        vector<TreeNode*>visi;
        visi.push_back(target);
        int dis=0;
        while(dis!=k){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left && visited(temp->left,visi)==false){
                    q.push(temp->left);
                    visi.push_back(temp->left);
                }
                if(temp->right && visited(temp->right,visi)==false){
                    q.push(temp->right);
                    visi.push_back(temp->right);
                }
                if(m.find(temp)!=m.end() && visited(m[temp],visi)==false){
                    q.push(m[temp]);
                    visi.push_back(m[temp]);
                }
            }
            dis++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<TreeNode*,TreeNode*>m;
        parent(root,m);
        helper(target,k,ans,m);
        return ans;
    }
};