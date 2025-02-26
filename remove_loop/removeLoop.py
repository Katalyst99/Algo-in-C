#!/usr/bin/env python3
"""The module for Remove Loop in Linked List"""


class Node:
    """Definition for a linked list node"""
    def __init__(self, val):
        self.val = val
        self.next = None


def findRemoveLoop(head):
    """Function that finds and removes a loop in a linked list"""
    slow, fast = head, head

    if fast is None or fast.next is None:
        return

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break

    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    while fast.next != slow:
        fast = fast.next
    fast.next = None


def printLinkedList(head):
    """Function to print a linked list"""
    tmp = set()
    while head:
        if head in tmp:
            print("Loop detected! Stopping print.")
            break
        print(head.val, end=" -> ")
        tmp.add(head)
        head = head.next
    print("NULL")


if __name__ == "__main__":
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)

    head.next.next.next.next.next = head.next.next

    findRemoveLoop(head)

    printLinkedList(head)
