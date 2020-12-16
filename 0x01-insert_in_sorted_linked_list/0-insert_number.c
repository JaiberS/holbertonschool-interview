#include "lists.h"

/**
 * insert_node - adds a new node at a listint_t list.
 * @n: new data
 * @head: first node
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int n)
{
	listint_t *new, *head2, *ant;
	unsigned int i = 0;

	if (head == NULL) {
		return (0);
    }
	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		*head = new;
		return (new);
	}
	head2 = *head;
    ant = NULL;
	for (;head2 != NULL && head2->n < n; ant = head2, head2 = head2->next, i++)
    ;
	if (head2 != NULL)
	{
		new->n = n;
		if (ant != NULL)
		{
			ant->next = new;
			new->next = head2;
		}
		else
		{
			new->next = *head;
			*head = new;
		}
		return (new);
	}
	free(new);
	return (NULL);
}