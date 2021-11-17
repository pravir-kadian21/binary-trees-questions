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

void preorder_recursive(struct node *root){
	if(root==NULL) return;

	cout << root->data << " ";
	preorder_recursive(root->left);
	preorder_recursive(root->right);
}

void inorder_recursive(struct node *root){
	if(root==NULL) return;

	
	inorder_recursive(root->left);
	cout << root->data << " ";
	inorder_recursive(root->right);
}


void postorder_recursive(struct node *root){
	if(root==NULL) return;

	
	postorder_recursive(root->left);
	postorder_recursive(root->right);
	cout << root->data << " ";
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

	preorder_recursive(root);
	cout << endl;
	inorder_recursive(root);
	cout << endl;
	postorder_recursive(root);
	cout << endl;

	return 0;
}