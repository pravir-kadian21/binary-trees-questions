#include<bits/stdc++.h>
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


vector<int>morrispreorder(node *root){
	vector<int>preorder;

	node*curr = root;

	while(curr!=NULL){
		
		if(curr->left==NULL){
			preorder.push_back(curr->data);
			curr = curr->right;
		}
		else{
			node *prev = curr->left;
			while(prev->right && prev->right!=curr){
				prev = prev->right;
			}
			if(prev->right==NULL){
				prev->right=curr;
				preorder.push_back(curr->data);
				curr = curr->left;
			}
			else{
				prev->right = NULL;
				
				curr = curr->right;
			}
		}
	}
	return preorder;
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

	vector<int>ans = morrispreorder(root);

	for(auto &it:ans){
		cout << it << " ";
	}
}