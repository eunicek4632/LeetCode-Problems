# Time Complexity: O(n)
# Space: O(n)
# This approach is using a DFS 
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        stack = [root]
        seq = []
        while len(stack) > 0:
            node = stack.pop()
# We have to push the right first if the node has both left and right child because we want the left child to be visited first so order does matter here
            if node.right != None:
                stack.append(node.right)
            if node.left != None:
                stack.append(node.left)
            
            seq.append(node.val)
        return seq
