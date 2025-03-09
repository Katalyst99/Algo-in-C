#!/usr/bin/env python3
"""The module for Partition List"""


class Node:
    """Definition for a linked list node"""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def partition(head: Node, x: int) -> Node:
    """Returns the modified List"""
    smallHead = Node(0)
    bigHead = Node(0)

    small = smallHead
    big = bigHead

    while head:
        if head.val < x:
            small.next = head
            small = small.next
        else:
            big.next = head
            big = large.next
        head = head.next

    small.next = bigHead.next
    big.next = None
    return smallHead.next
