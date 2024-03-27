#include "binary_trees.h"

/**
 * find_node - find a node in a BT
 *
 * @root: root of the tree to evaluate
 *
 * @node: node to find
 *
 * Return: 1 if node exists. 0 if otherwise
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{
	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}

/**
 * cross_check - cross the tree and match each node for existence validation
 *
 * @root: root node of the tree
 *
 * @node: current node to evaluate
 *
 * Return: 1 if valid BST. 0 if otherwise
 */
int cross_check(binary_tree_t *root, binary_tree_t *node)
{
	int temp = 0;

	if (root && node)
	{
		temp = find_node(root, node);
		if (node->left)
			temp &= cross_check(root, node->left);
		if (node->right)
			temp &= cross_check(root, node->right);
		return (temp);
	}
	return (0);
}

/**
 * binary_tree_is_bst - checks if a BT is a valid binary search tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is valid. 0 otherwise. 0 if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (cross_check((binary_tree_t *)tree, (binary_tree_t *)tree));
}
