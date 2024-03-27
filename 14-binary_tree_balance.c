#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height;
	size_t left_height;

	if (tree == NULL)
		return (0);

	left_height = (tree->left) ? 1 + binary_tree_height(tree->left) : 1;
	right_height = (tree->right) ? 1 + binary_tree_height(tree->right) : 1;

	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}


