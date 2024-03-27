#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to the  lowest common ancestor of the two given nodes
 * or return NULL, if no common ancestor is found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	left = first->parent;
	right = second->parent;

	if (first == right || !left || (!left->parent && right))
		return (binary_trees_ancestor(first, right));
	else if (left == second || !right || (!right->parent && left))
		return (binary_trees_ancestor(left, second));

	return (binary_trees_ancestor(left, right));
}

