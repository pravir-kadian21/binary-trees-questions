/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL) return;
    
    int sum=0;
    if(root->left){
        sum+=(root->left->data);
    }
    if(root->right){
        sum+=(root->right->data);
    }
    if(sum<root->data){
        if(root->left)	root->left->data = root->data;
    	if(root->right) root->right->data = root->data;
    }
    else{
		root->data = sum;	
    }
    changeTree(root->left);
    changeTree(root->right);
    
    int ans = 0;
    if(root->left) ans+=(root->left->data);
    if(root->right) ans+=(root->right->data);
    
    if(root->left || root->right)
    	root->data = ans;
    
}  