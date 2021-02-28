/// Time Complexity: O(n^2)
/// Space: O(n)

struct TreeNode * recur(int start_in, int end_in, int start_post, int end_post, int * inorder, int * postOrder){
    if(start_in > end_in || start_post > end_post){
        return NULL;
    }

    struct TreeNode * tmp = malloc(sizeof(struct TreeNode));
    /// The last entry in the postorder array would be the root of the tree
    tmp->val = postOrder[end_post];

    int index;
    /// Find the position of root in the inorder array and partition it into left and right subtree
    for(int i = start_in; i <= end_in; i++){
        if(tmp->val == inorder[i]){
            index = i;
            //printf("%d\n", i);
        }
    }
    //printf("%d, %d, %d, %d\n", start_in, index - 1, start_post, start_post + index - start_in - 1);
    /// Recursively build the left and right subtree
    tmp->left = recur(start_in, index - 1, start_post, start_post + index - start_in - 1, inorder, postOrder);
    tmp->right = recur(index + 1, end_in, start_post + index - start_in, end_post - 1, inorder, postOrder);
    return tmp;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return recur(0, inorderSize - 1, 0, postorderSize - 1, inorder, postorder);
}
