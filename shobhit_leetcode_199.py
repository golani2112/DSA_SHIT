# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        q = collections.deque()
        if root:
            q.append(root)

        while q:
            nodes_on_same_level = []
            for _ in range(len(q)):
                node = q.popleft()
                nodes_on_same_level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(nodes_on_same_level)
        
        res = [nodes[-1] for nodes in res]
        return res
