#include "binary_trees.h"
/**
 * binary_tree_leaves - number of leaves in a tree
 * @tree: tree
 * Return: leaves number
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t f = 0, l = 0, n = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l = binary_tree_leaves(tree->left);
		n = binary_tree_leaves(tree->right);
		f = l + n;
		return ((!l && !n) ? f + 1 : f + 0);
	}
}
