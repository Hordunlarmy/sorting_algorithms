#include "sort.h"

/**
 * print_list - Prints a list of integers
 * @list: The list to be printed
 * Return: nothing
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    for (; list != NULL; list = list->next)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
    }
    printf("\n");
}



