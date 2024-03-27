#include "binary_trees.h"

/**
 * hlp_sort - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: position where the array starts
 * @last: position where the array ends
 *
 * Return: tree created
 */
avl_t *hlp_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *temp;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		temp = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (temp == NULL)
			return (NULL);
		root = (avl_t *)temp;
		root->left = hlp_sort(root, array, begin, mid - 1);
		root->right = hlp_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - build an AVL tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 *
 * Return: AVL tree from sorted array
 *
 * Description: No duplicate value in the array
 *              Rotation not allowed
 *              Only 2 functions in file
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (hlp_sort(NULL, array, 0, ((int)(size)) - 1));
}
