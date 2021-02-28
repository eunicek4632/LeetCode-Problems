# Time Complexity: O(n)
# Space: O(n)
# We can save the result of inorder traversal to an array and 
# check if the array is sorted

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        arr = []

        def inorder(root):
            if root == None:
                return
            
            inorder(root.left)
            arr.append(root.val)
            inorder(root.right)
            
        inorder(root)
        print(arr)
        for i in range(len(arr) - 1):
            if arr[i] >= arr[i + 1]:
                return False
            
        return True