#!/usr/bin/env python3
"""The module for Detect Loop in Linked List"""


class Node:
    """Definition for a linked list node"""
    def __init__(self, val=0):
        self.val = val
        self.next = None


def findLoop(head):
    """Function that detects a loop in a linked list"""
    slow, fast = head, head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True

    return False


def createLinkedList(vals):
    '''Function to create a linked list and insert nodes'''
    if not vals:
        return None

    head = Node(vals[0])
    current = head
    nodes = {0: head}

    for i in range(1, len(vals)):
        new = Node(vals[i])
        current.next = new
        current = new
        nodes[i] = new

    return head, nodes


if __name__ == "__main__":
    head, nodes = createLinkedList([1, 2, 3, 4, 5])

    nodes[4].next = nodes[2]

    if findLoop(head):
        print("Loop detected!")
    else:
        print("No loop detected.")
