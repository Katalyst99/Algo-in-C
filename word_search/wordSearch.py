#!/usr/bin/env python3
"""The module for Word Search"""


def exist(board, word):
    rows, columns = len(board), len(board[0])

    def dfs(x, y, index):
        """The DFS function"""
        if index == len(word):
            return True

        if (x < 0 or y < 0 or x >= rows or y >= columns or
            board[x][y] != word[index]):
            return False

        tmp = board[x][y]
        board[x][y] = '#'

        found = (dfs(x+1, y, index+1) or
                 dfs(x-1, y, index+1) or
                 dfs(x, y+1, index+1) or
                 dfs(x, y-1, index+1))

        board[x][y] = tmp
        return found

    for i in range(rows):
        for j in range(columns):
            if dfs(i, j, 0):
                return True
    return False


board = [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
]
word = "ABCCED"
output = exist(board, word)
print(f"Does the word '{word}' exist in the board? {output}")
