/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void parent(TreeNode *root,map<TreeNode*,TreeNode*>&m,TreeNode *&target,int B){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        
            TreeNode *temp = q.front();
            q.pop();
            if(temp->val==B){
                target = temp;
            }
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


bool isVisited(TreeNode*root,vector<TreeNode*>&visi){
        auto it = find(visi.begin(),visi.end(),root);
        if(it!=visi.end()) return true;
        
        return false;
}
int helper(TreeNode *target,map<TreeNode*,TreeNode*>&m){

    queue<TreeNode*>q;
    q.push(target);
    int dis=0;
    vector<TreeNode*>visi;
    visi.push_back(target);
    while(!q.empty()){
        int size = q.size();
        int flag=0;
        for(int i=0;i<size;i++){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left && isVisited(temp->left,visi)==false){
                flag=1;
                q.push(temp->left);
                visi.push_back(temp->left);
            }
            if(temp->right && isVisited(temp->right,visi)==false){
                flag=1;
                q.push(temp->right);
                visi.push_back(temp->right);
            }
            if(m.find(temp)!=m.end() && isVisited(m[temp],visi)==false){
                flag=1;
                q.push(m[temp]);
                visi.push_back(m[temp]);
            }
        }
        if(flag==1) dis++;
    }
    return dis;
}


int Solution::solve(TreeNode* root, int B) {
    if(root==NULL) return 0;
    map<TreeNode*,TreeNode*>m;

    TreeNode *target=NULL;
    

    parent(root,m,target,B);
    return helper(target,m);
}/*  */