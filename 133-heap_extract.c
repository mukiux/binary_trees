#include "binary_trees.h"

/**
 * count_heap_nodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int count_heap_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_heap_nodes(root->left) +
		    count_heap_nodes(root->right));
}


/**
 * bubble_down - Puts a node value in a correct position in the heap
 * @parent: Pointer to heap's node
 *
 * Return: void
 */
void bubble_down(heap_t *parent)
{
	int temp;
	heap_t *max_child = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		max_child = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			max_child = parent->right;

		if (max_child->n > parent->n)
		{
			temp = parent->n;
			parent->n = max_child->n;
			max_child->n = temp;
		}

		parent = max_child;
	}
}


/**
 * get_parent - finds the parent node for a certain node
 * @root: pointer to heap's node
 * @idx: pointer to index of the current node
 * @sidx: pointer to index been searched
 *
 * Return: pointer to heap's node
 */
heap_t *get_parent(heap_t *root, int idx, int sidx)
{
	heap_t *left = NULL, *right = NULL;

	if (!root || idx > sidx)
		return (NULL);

	if (idx == sidx)
		return (root);

	left = get_parent(root->left, idx * 2 + 1, sidx);
	if (left)
		return (left);

	right = get_parent(root->right, idx * 2 + 2, sidx);
	if (right)
		return (right);

	return (NULL);
}


/**
 * remove_last_node - removes the last node of a heap
 * @root: double pointer to heap's root node
 * @parent: pointer to parent node from which to remove the last node
 *
 * Return: void
 */
void remove_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	bubble_down(*root);
}


/**
 * heap_extract - extracts the root node of a MBH
 * @root: double pointer to the root node of heap
 *
 * Return: value stored in the root node. 0 if failure
 *
 * Description: Root node must be freed and replace
 *              with level-order node of the heap
 *              Once replaced, heap must be rebuilt if necessary
 */
int heap_extract(heap_t **root)
{
	int nodes, sidx = 0, max_val = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	max_val = (*root)->n;
	nodes = count_heap_nodes(*root);

	sidx = (nodes - 2) / 2;
	parent = get_parent(*root, 0, sidx);

	remove_last_node(root, parent);

	return (max_val);
}
