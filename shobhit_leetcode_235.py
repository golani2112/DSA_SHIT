# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        curr = root
        #2 Cases
        # Case 1 : Both p, q lie in left or right subtree and share a common anecestopr. In that case the split node which splits p and q is the LCA
        # Case 2: If current node points at one of p or q then that node itself would be LCA
        while curr:
            if p.val > curr.val and q.val > curr.val:
                curr = curr.right #p, q in right sub tree
            elif p.val < curr.val and q.val < curr.val:
                curr = curr.left #p,q in left sub tree
            else:
                return curr #As per Case 1 or Case 2.
                
