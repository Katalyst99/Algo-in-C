#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function that checks if two words differ by a single letter
bool singleDiff(const char *a, const char *b) 
{
    int i;
    int diff = 0;

    for (i = 0; a[i] && b[i]; i++) 
    {
        if (a[i] != b[i] && ++diff > 1)
            return false;
    }
    return diff == 1;
}


/**
 * wordLadder - Returns the length of the shortest transformation sequence
 * @beginWord: The first word
 * @endWord: The last word
 * @wordList: The list of words
 * @wordListSize: The size of the wordList
 * Return: 0, if no such sequence exists
 */
int wordLadder(char *beginWord, char *endWord, char **wordList, int wordListSize) 
{
    bool endWordFound = false;

    for (int i = 0; i < wordListSize; i++) 
    {
        if (strcmp(wordList[i], endWord) == 0) 
	{
            endWordFound = true;
            break;
        }
    }
    if (!endWordFound)
	    return 0;

    bool *visited = calloc(wordListSize, sizeof(bool));

    typedef struct {
        char *word;
        int level;
    } qNode;

    qNode *queue = malloc((wordListSize + 1) * sizeof(qNode));
    int head = 0, tail = 0;

    queue[tail++] = (qNode){ .word = beginWord, .level = 1 };

    while (head < tail) 
    {
        qNode current = queue[head++];
        for (int i = 0; i < wordListSize; i++) 
	{
            if (!visited[i] && singleDiff(current.word, wordList[i])) 
	    {
                if (strcmp(wordList[i], endWord) == 0) 
		{
                    free(visited);
                    free(queue);
                    return current.level + 1;
                }
                visited[i] = true;
                queue[tail++] = (qNode){ .word = wordList[i], .level = current.level + 1 };
            }
        }
    }
    free(visited);
    free(queue);
    return 0;
}

int main() 
{
    char *start = "hit";
    char *end   = "cog";
    char *list[] = { "hot", "dot", "dog", "lot", "log", "cog" };
    int listSize = sizeof(list) / sizeof(list[0]);

    int output = wordLadder(start, end, list, listSize);
    printf("Shortest transformation length: %i\n", output);
    return 0;
}
