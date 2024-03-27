#include "binary_trees.h"

/**
 * max - Computes the maximum of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The maximum of a and b.
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
int height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = height(tree->left);
		int right_height = height(tree->right);

		return (1 + max(left_height, right_height));
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = height(tree->left);
		int right_height = height(tree->right);
		int height_diff = abs(left_height - right_height);

		if (height_diff <= 1 &&
		    is_avl_helper(tree->left) &&
		    is_avl_helper(tree->right))
			return (1);
		else
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 *         If NULL, return 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree));
}
