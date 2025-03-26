#!/usr/bin/env python3
"""The module for Binary Tree Level Order Traversal"""


class Node:
    """Definition for a tree node"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def levelOrderDFS(root):
    """perform level order traversal using DFS"""
    output = []

    def dfs(node, level):
        """Depth-First Search with recursion"""
        if not node:
            return

        if len(output) == level:
            output.append([])

        output[level].append(node.val)

        dfs(node.left, level + 1)
        dfs(node.right, level + 1)

    dfs(root, 0)
    return output


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.right = Node(6)

print(levelOrderDFS(root))
