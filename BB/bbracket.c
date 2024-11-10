#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * isMatch - Checks if the given pair of characters are matching brackets.
 * @open: The opening bracket character.
 * @close: The closing bracket character.
 *
 * Return: true if the pair matches, false otherwise.
 */
bool isMatch(char open, char close)
{
	return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
}

/**
 * isBalanced - Checks if a string of brackets is balanced.
 * @str: The input string containing brackets.
 *
 * This function uses a stack to ensure that every opening bracket has a
 * corresponding closing bracket and that they are properly nested.
 *
 * Return: true if the string is balanced, false otherwise.
 */
bool isBalanced(char str[])
{
	char stack[100];
	int top = -1;

	for (int i =0; i < strlen(str); i++)
	{
		char current = str[i];
		if (current == '(' || current == '[' || current == '{')
		{
			stack[++top] = current;
		}
		else if (current == ')' || current == ']' || current == '}')
		{
			if (top == -1 || !isMatch(stack[top--], current))
			{
				return false;
			}
		}
	}
	return (top == -1);
}

/**
 * main - Tests the isBalanced function with various cases.
 *
 * This function runs several test cases to check if the isBalanced function
 * works correctly with different input strings.
 *
 * Return: Always 0.
 */
int main() {
    char test1[] = "[]";
    char test2[] = "][";
    char test3[] = "[{()}]";
    char test4[] = "[()]{}";
    char test5[] = "{[)]}";

    // Display results of the tests
    printf("Test 1: %s - %s\n", test1, isBalanced(test1) ? "Balanced" : "Not Balanced");
    printf("Test 2: %s - %s\n", test2, isBalanced(test2) ? "Balanced" : "Not Balanced");
    printf("Test 3: %s - %s\n", test3, isBalanced(test3) ? "Balanced" : "Not Balanced");
    printf("Test 4: %s - %s\n", test4, isBalanced(test4) ? "Balanced" : "Not Balanced");
    printf("Test 5: %s - %s\n", test5, isBalanced(test5) ? "Balanced" : "Not Balanced");

    return 0;
}
