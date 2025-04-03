#!/usr/bin/env python3
"""
The module for Converting Sorted List to Binary Search Tree.
"""
from typing import Optional


class listNode:
    """Definition for a singly-linked list."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Node:
    """Definition for a binary tree node."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """The class for the algorithm's implementation"""
    def sortList2BST(self, head: Optional[listNode]) -> Optional[Node]:
        """Converts a sorted singly linked list into a height-balanced BST."""
        if not head:
            return None

        mid = self.findMid(head)

        root = Node(mid.val)

        if head == mid:
            return root

        root.left = self.sortList2BST(head)
        root.right = self.sortList2BST(mid.next)

        return root

    def findMid(self, head: listNode) -> listNode:
        """
        Finds the middle node of the linked list using slow and fast pointers.
        """
        prev = None
        slow = head
        fast = head

        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        if prev:
            prev.next = None
        return slow


def inorderTraversal(root: Optional[Node]):
    if root:
        inorderTraversal(root.left)
        print(root.val, end=" ")
        inorderTraversal(root.right)


head = listNode(-10, listNode(-3, listNode(0, listNode(5, listNode(9)))))

solution = Solution()
treeRoot = solution.sortList2BST(head)

print("Inorder Traversal of BST:")
inorderTraversal(treeRoot)
print('\n')
