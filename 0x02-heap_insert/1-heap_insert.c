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
	int max_level = 0;

	new = malloc(sizeof(heap_t));
	new->right = NULL;
	new->left = NULL;
	if (new == NULL) {
		return (NULL);
	}
	if (*root == NULL) {
		new->n = value;
		new->parent = NULL;
		*root = new;
		return (*root);
	}
	head = *root;

	while (head->right != NULL) {
		head = head->right;
		max_level++;
	}
	head = *root;

	new = heap_insert_with_levels(root, value, 0, max_level + 1);

	return (new);
}


/**
 * heap_insert_with_levels - Write a function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert_with_levels(heap_t **root, int value, int level, int max_level)
{
    heap_t *new, *head;

	new = malloc(sizeof(heap_t));
	new->right = NULL;
	new->left = NULL;
	if (new == NULL) {
		return (NULL);
	}
	if (*root == NULL) {
		new->n = value;
		new->parent = NULL;
		*root = new;
		return (*root);
	}
	head = *root;
	if (level == max_level) {
		while(head->parent != NULL) {
			head = head->parent;
		}
		new = heap_insert_with_levels(&head->right, value, level + 1, max_level);
	}
	if (value > head->n) {
		new->n = head->n;
		head->n = value;
		if (head->left == NULL) {
			head->left = new;
			new->parent = head;
		} else if (head->right == NULL) {
			head->right = new;
			new->parent = head;
		} else {
			new = heap_insert_with_levels(&head->left, value, level + 1, max_level);
		}
		return (head);
	} else {
		new->n = value;
		if (head->left == NULL) {
			head->left = new;
			new->parent = head;
		} else if (head->right == NULL) {
			head->right = new;
			new->parent = head;
		} else {
			new = heap_insert_with_levels(&head->left, value, level + 1, max_level);
		}
		return (new);
	}

	return (head);
}