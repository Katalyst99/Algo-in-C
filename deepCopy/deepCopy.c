#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    int *scores;
    int num_scores;
} Person;

/**
 * newPerson - Function to create a new person
 * @name: The name of the person
 * @age: The age of the person
 * @scores: The scores of the person
 * @num_scores: The number of the scores of the person
 * Return: The created new person
 */
Person *newPerson(const char *name, int age, int *scores, int num_scores) 
{
    Person *p = (Person *)malloc(sizeof(Person));
    if (!p) {
        perror("Memory allocation failed");
        exit(1);
    }

    p->name = (char *)malloc(strlen(name) + 1);
    if (!p->name) 
    {
        perror("Memory allocation failed");
        exit(1);
    }
    strcpy(p->name, name);

    p->age = age;

    p->num_scores = num_scores;
    p->scores = (int *)malloc(num_scores * sizeof(int));
    if (!p->scores) {
        perror("Memory allocation failed");
        exit(1);
    }
    for (int i = 0; i < num_scores; i++) 
    {
        p->scores[i] = scores[i];
    }
    return p;
}

/**
 * deepCopyPerson - Function to deep copy a Person struct
 * @original: The original attributes of a person
 * Return: The deep copy
 */
Person *deepCopyPerson(const Person *original) 
{
    if (!original) {
	return NULL;
    }
    return newPerson(original->name, original->age, original->scores, original->num_scores);
}

// Function to print a Person struct
void printPerson(const Person *p) 
{
    if (!p) return;
    printf("Name: %s, Age: %i, Scores: [", p->name, p->age);
    for (int i = 0; i < p->num_scores; i++) 
    {
        printf("%d", p->scores[i]);
        if (i < p->num_scores - 1) printf(", ");
    }
    printf("]\n");
}

// Function to free memory allocated for a Person struct
void freePerson(Person *p) 
{
    if (!p) return;
    free(p->name);
    free(p->scores);
    free(p);
}

int main() 
{
    int scores[] = {90, 85, 80};
    Person *original = newPerson("Alice", 25, scores, 3);

    Person *copy = deepCopyPerson(original);

    copy->name[0] = 'E';
    copy->age = 26;
    copy->scores[0] = 99;

    printf("Original: ");
    printPerson(original);
    printf("Copy: ");
    printPerson(copy);

    freePerson(original);
    freePerson(copy);

    return 0;
}
