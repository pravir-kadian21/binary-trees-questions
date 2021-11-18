#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node*left;
	struct node*right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

vector<vector<int>> pre_in_post(struct node *root){
	vector<vector<int>>ans;
	vector<int>pre,in,post;

	stack<pair<node*,int>>s;

	s.push({root,1});
	while(!s.empty()){
		pair<node*,int>p;
		p = s.top();
		s.pop();

		if(p.second == 1){
			pre.push_back(p.first->data);
			s.push({p.first,++p.second});
			if(p.first->left!=NULL){
				s.push({p.first->left,1});
			}	
		}
		else if(p.second==2){
			in.push_back(p.first->data);
			s.push({p.first,++p.second});
			if(p.first->right!=NULL){
				s.push({p.first->right,1});
			}
		}
		else{
			post.push_back(p.first->data);
		}
	}
	ans.push_back(pre);
	ans.push_back(in);
	ans.push_back(post);
	return ans;
}


int main(){

	struct node *root = new node(1);
	root->left = new node(2);
	root->left->left = new node(4);
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	root->left->right = new node(5);
	root->left->right->left = new node(6);
	root->left->right->right = NULL;
	root->left->right->left->left = NULL;
	root->left->right->left->right = NULL;

	root->right = new node(3);
	root->right->left = new node(7);
	root->right->left->left=NULL;
	root->right->left->right=NULL;
	root->right->right = new node(8);
	root->right->right->left = new node(9);
	root->right->right->right = new node(10);
	root->right->right->left->left = NULL;
	root->right->right->left->right = NULL;
	root->right->right->right->right = NULL;
	root->right->right->right->left = NULL;

	vector<vector<int>>ans = pre_in_post(root);

	for(int i=0;i<3;i++){
		for(int j=0;j<ans[0].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}