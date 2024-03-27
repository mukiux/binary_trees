#include "binary_trees.h"

/**
 * binary_tree_nodes -  counts the leaves in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number of leaves
 *
 * Return: If tree is NULL, the function must return 0
 *
 * A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_node;
	size_t right_node;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_node = binary_tree_nodes(tree->left);
	right_node = binary_tree_nodes(tree->right);

	return (1 + (left_node + right_node));
}
