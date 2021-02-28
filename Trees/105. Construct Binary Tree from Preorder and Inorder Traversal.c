/// Time Complexity: O(n^2)
/// Space: O(n)

struct TreeNode* recur(int start_in, int end_in, int start_pre, int end_pre, int* preorder, int* inorder){
    if(start_in > end_in || start_pre > end_pre){
        return NULL;
    }


    struct TreeNode * tmp = malloc(sizeof(struct TreeNode));
    /// The first entry in the preorder array would be the root of the tree
    tmp->val = preorder[start_pre];
    int index;

    /// Find the position of root in the inorder array and partition it into left and right subtree
    for(int i = start_in; i <= end_in; i++){
        if(tmp->val == inorder[i]){
            index = i;
            printf("%d\n", i);
        }
    }
    /// Recursively build the left and right subtree
    tmp->left = recur(start_in, index - 1, start_pre + 1, end_pre, preorder, inorder);
    tmp->right = recur(index + 1, end_in, start_pre + index - start_in + 1, end_pre, preorder, inorder);
    return tmp;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return recur(0, inorderSize - 1, 0, preorderSize - 1, preorder, inorder);
}
