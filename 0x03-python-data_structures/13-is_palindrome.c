#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - identify if a singly linked list is palindrome
 * @head: pointer to pointer of the head of the list
 * Return: 1 if it is a palindrome, else 0
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

    // Compare the reversed first half with the second half
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

    // Restore the original list
    slow = prev_slow;
    prev_slow = NULL;

    while (slow != NULL)
    {
        listint_t *temp = slow->next;
        slow->next = prev_slow;
        prev_slow = slow;
        slow = temp;
    }

    *head = prev_slow;

    return is_palindrome;
}
