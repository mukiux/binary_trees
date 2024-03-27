#include "binary_trees.h"

/**
 * binary_tree_height - gets the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0;
		int right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}

/**
 * print_at_level - print node, especific level
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * @level: level to print
 *
 * Return: void
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - goes through a BT using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = binary_tree_height(tree);
	size_t i;

	if (tree && func)
	{
		for (i = 1; i <= height + 1; i++)
			print_at_level(tree, func, i);
	}
}
