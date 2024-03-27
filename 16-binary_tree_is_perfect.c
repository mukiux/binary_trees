#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 *
 * @tree: a pointer to the node to measure the depth
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->left));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_depth;
	int right_depth;

	if (tree == NULL)
		return (0);

	left_depth = binary_tree_depth(tree->left);
	right_depth = binary_tree_depth(tree->right);

	if (left_depth == right_depth)
	{
		if (tree->left == NULL || tree->right == NULL)
			return (1);
		else
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
	}

	return (0);
}
