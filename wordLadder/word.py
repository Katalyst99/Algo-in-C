#!/usr/bin/env python3
"""The module for Word Ladder"""
from collections import deque
import string


def wordLadder(beginWord, endWord, wordList):
    """
    Returns the number of words in the shortest transformation sequence,
    from beginWord to endWord, or 0 if no such sequence
    """
    wordSet = set(wordList)
    if endWord not in wordSet:
        return 0

    Q = deque([(beginWord, 1)])
    if beginWord in wordSet:
        wordSet.remove(beginWord)

    while Q:
        current, steps = Q.popleft()
        for i in range(len(current)):
            for char in string.ascii_lowercase:
                if char == current[i]:
                    continue
                nextWord = current[:i] + char + current[i+1:]
                if nextWord == endWord:
                    return steps + 1
                if nextWord in wordSet:
                    wordSet.remove(nextWord)
                    Q.append((nextWord, steps + 1))
    return 0


if __name__ == "__main__":
    begin = "hit"
    end = "cog"
    word_list = ['hot', 'dot', 'dog', 'lot', 'log', 'cog']
    print("Shortest transformation length:", wordLadder(begin, end, word_list))
