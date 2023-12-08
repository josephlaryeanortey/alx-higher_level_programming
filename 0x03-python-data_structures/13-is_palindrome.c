#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to pointer of the head of the list
 * @n: integer to add in listint_t list
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;
    return new_node;
}

/**
 * is_palindrome - identify if a singly linked list is palindrome
 * @head: pointer to pointer of the head of the list
 * Return: 1 if it is palindrome else 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *reversed = NULL;
    listint_t *current = *head;

    // Create a reversed copy of the list
    while (current != NULL)
    {
        add_nodeint(&reversed, current->n);
        current = current->next;
    }

    // Compare the original list with the reversed list
    current = *head;
    while (current != NULL && reversed != NULL)
    {
        if (current->n != reversed->n)
        {
            free_listint(&reversed);  // Free the reversed list
            return 0;  // Not a palindrome
        }

        current = current->next;
        reversed = reversed->next;
    }

    free_listint(&reversed);  // Free the reversed list
    return 1;  // Palindrome
}
