/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int recur(struct TreeNode* root, int sum){
    //base case
    if(root == NULL){
        return 0;
    }

    else{
        sum += root->val;
        //leaf nodes
        if(root->left == NULL && root->right == NULL){
            return sum;
        }
        //internal nodes
        else{
            return recur(root->left, sum * 10) + recur(root->right, sum * 10);
        }
    }
    return sum;
}


int sumNumbers(struct TreeNode* root){
    return recur(root, 0);
}
