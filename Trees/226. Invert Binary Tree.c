/// Time Complexity: O(n)
/// Space: O(1)

void recur(struct TreeNode * root){
    /// Base Case
    if(root == NULL){
        return;
    }

    /// Swap the left and right subtree for root
    struct TreeNode * tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    /// Do the recursion on the left and right subtree
    recur(root->left);
    recur(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    recur(root);
    return root;
}
