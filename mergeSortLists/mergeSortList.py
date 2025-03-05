#!/usr/bin/env python3
"""The module for Merge K Sorted Lists"""
from heapq import heappush, heappop


class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __lt__(self, other):
        return self.val < other.val


def mergeKLists(lists):
    """Merges all the linked-lists into 1 sorted linked-list and return it."""
    minHeap = []

    for h in lists:
        if h:
            heappush(minHeap, h)
    dummy = Node(0)
    current = dummy

    while minHeap:
        tail = heappop(minHeap)
        current.next = tail
        current = current.next

        if tail.next:
            heappush(minHeap, tail.next)

    return dummy.next


def createLinkedList(arr):
    """Helper function to create a linked list from a list"""
    dummy = Node(0)
    current = dummy
    for num in arr:
        current.next = Node(num)
        current = current.next
    return dummy.next


def printList(head):
    """Helper function to print a linked list"""
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("NULL")


lists = [
    createLinkedList([1, 4, 5]),
    createLinkedList([1, 3, 4]),
    createLinkedList([2, 6])
]

print("Merged List:")
mergedHead = mergeKLists(lists)
printList(mergedHead)
