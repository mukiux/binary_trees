#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to new root node of the tree rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *hlp, *temp;

	if (tree == NULL)
		return (NULL);

	if (tree->left)
	{
		temp = tree->left->right;
		hlp = tree->left;
		hlp->parent = tree->parent;
		hlp->right = tree;
		tree->parent = hlp;
		tree->left = temp;
		if (temp)
			temp->parent = tree;
		return (hlp);
	}
	return (NULL);
}
