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

bool root_to_node(node *root,vector<int>&ans,int target){
	if(root==NULL) return false;

	ans.push_back(root->data);

	if(root->left == NULL && root->right==NULL){
		
		return true;
	}

	if(root_to_node(root->left,ans,target)||root_to_node(root->right,ans,target)){
		return true;
	}
	ans.pop_back();
	return false;

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

	vector<int>ans;
	int target; cin>>target;
	if(root_to_node(root,ans,target)){
		for(int i=0;i<ans.size();i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << "not found" << endl;
	}
}/*  */