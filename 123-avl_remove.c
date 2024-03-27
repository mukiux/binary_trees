#include "binary_trees.h"

/**
 * bal_factor - Measures balance factor of an AVL tree
 * @tree: tree to go through
 *
 * Return: balanced factor
 */
int bal_factor(avl_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * rebalance - Rebalances an AVL tree
 * @tree: pointer to the root of the AVL tree
 *
 * Return: pointer to the new root of the AVL tree after rebalancing
 */
avl_t *rebalance(avl_t *tree)
{
	int balance;
	avl_t *new_root = tree;

	balance = bal_factor(tree);

	if (balance > 1)
	{
		if (bal_factor(tree->left) >= 0)
			new_root = binary_tree_rotate_right(tree);
		else
		{
			tree->left = binary_tree_rotate_left(tree->left);
			new_root = binary_tree_rotate_right(tree);
		}
	}
	else if (balance < -1)
	{
		if (bal_factor(tree->right) <= 0)
			new_root = binary_tree_rotate_left(tree);
		else
		{
			tree->right = binary_tree_rotate_right(tree->right);
			new_root = binary_tree_rotate_left(tree);
		}
	}

	return (new_root);
}

/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 *
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}
		else
		{
			bst_t *temp = root->right;

			while (temp && temp->left != NULL)
				temp = temp->left;
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}

	return (root);
}

/**
 * avl_remove - remove a node from an AVL tree
 * @root: pointer to root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree
 *         after removing desired value and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	root = (avl_t *)bst_remove((bst_t *)root, value);

	/* Rebalance the AVL tree */
	root = rebalance(root);

	return (root);
}
