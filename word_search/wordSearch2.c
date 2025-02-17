#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int directions[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

/**
 * dfs - Performs DFS and check if the word is found
 * @board: The grid of chars
 * @word: A string
 * Return: True, if word found else False
 */
bool dfs(char** board, int rows, int columns, int x, int y, char* word, int index) 
{
    if (index == strlen(word)) 
    {
        return true;
    }

    if (x < 0 || y < 0 || x >= rows || y >= columns || board[x][y] != word[index]) 
    {
        return false;
    }
    
    char tmp = board[x][y];
    board[x][y] = '#';
    
    for (int i = 0; i < 4; i++) 
    {
        int newRow = x + directions[i][0];
        int newCol = y + directions[i][1];
        
        if (dfs(board, rows, columns, newRow, newCol, word, index + 1)) 
	{
            return true;
        }
    }
    
    board[x][y] = tmp;
    
    return false;
}

/**
 * exist - Main function to check if the word exists in the grid
 * @board: The grid of chars
 * @word: The string
 * @rows: The rows in the grid
 * @columns: The columns in the grid
 * Return: True, if word exists in grid else False
 */
bool exist(char** board, int rows, int columns, char* word) 
{
    for (int x = 0; x < rows; x++) 
    {
        for (int y = 0; y < columns; y++) 
	{
            if (dfs(board, rows, columns, x, y, word, 0)) 
	    {
                return true;
            }
        }
    }
    return false;
}

int main() 
{
    int rows = 3;
    int columns = 4;

    char** board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) 
    {
        board[i] = (char*)malloc(columns * sizeof(char));
    }

    board[0][0] = 'A'; board[0][1] = 'B'; board[0][2] = 'C'; board[0][3] = 'E';
    board[1][0] = 'S'; board[1][1] = 'F'; board[1][2] = 'C'; board[1][3] = 'S';
    board[2][0] = 'A'; board[2][1] = 'D'; board[2][2] = 'E'; board[2][3] = 'E';

    char word[] = "ABCCED";

    if (exist(board, rows, columns, word)) {
        printf("The word '%s' exists in the grid.\n", word);
    } else {
        printf("The word '%s' does not exist in the grid.\n", word);
    }

    for (int i = 0; i < rows; i++) 
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
