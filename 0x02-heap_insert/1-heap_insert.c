#include "binary_trees.h"

/**
 * heap_insert - Write a function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new, *head;

	new = malloc(sizeof(heap_t));
	if (new == NULL) {
		return (NULL);
	}
	head = *root;
	if (head == NULL) {
		new->right = NULL;
		new->left = NULL;
		new->n = value;
		new->parent = NULL;
		head = new;
		return (head);
	}

	return (new);
}
