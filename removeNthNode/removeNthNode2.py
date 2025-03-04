#!/usr/bin/env python3
"""The module for Removing Nth Node from End of List"""


class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def removeNthFromEnd(head: Node, n: int) -> Node:
    """Function to remove nth node from end of list"""
    dummy = Node(0, head)
    fast = slow = dummy

    for _ in range(n + 1):
        fast = fast.next

    while fast:
        fast = fast.next
        slow = slow.next

    slow.next = slow.next.next
    return dummy.next


def printList(head):
    """Helper function to print the list"""
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("NULL")


def createLinkedList(arr):
    """Helper function to create a linked list from a list"""
    dummy = Node(0)
    current = dummy
    for num in arr:
        current.next = Node(num)
        current = current.next
    return dummy.next


head = createLinkedList([1, 2, 3, 4, 5])
print("Original List:")
printList(head)

n = 2
head = removeNthFromEnd(head, n)

print("Modified List:")
printList(head)
