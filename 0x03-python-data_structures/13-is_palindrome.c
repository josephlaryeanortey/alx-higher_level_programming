#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - reverses a listint_t list
 * @head: pointer to pointer of the head of the list
 */
void reverse_list(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/**
 * is_palindrome - identify if a singly linked list is palindrome
 * @head: pointer to pointer of the head of the list
 * Return: 1 if it is palindrome else 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *prev_slow = NULL, *second_half = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return 1;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        // Reverse the first half of the list
        listint_t *temp = slow;
        slow = slow->next;
        temp->next = prev_slow;
        prev_slow = temp;
    }

    // Adjust pointers for odd length of the list
    if (fast != NULL)
        slow = slow->next;

    second_half = slow;

    // Reverse the first half back to its original order
    reverse_list(&prev_slow);

    // Compare the original first half with the second half
    while (prev_slow != NULL && second_half != NULL)
    {
        if (prev_slow->n != second_half->n)
        {
            is_palindrome = 0;
            break;
        }

        prev_slow = prev_slow->next;
        second_half = second_half->next;
    }

    // Reverse the first half back to its original order
    reverse_list(&prev_slow);

    return is_palindrome;
}
