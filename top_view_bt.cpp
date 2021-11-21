map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            m[temp.second.first][temp.second.second].insert(temp.first->val);
            if(temp.first->left){
                
                q.push({temp.first->left,{temp.second.first-1,temp.second.second+1}});
            }
            if(temp.first->right){
                q.push({temp.first->right,{temp.second.first+1,temp.second.second+1}});
            }
        }