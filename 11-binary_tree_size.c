#include "binary_trees.h"
/**
 * binary_tree_size -  the size of a tree returned
 * @tree: tree
 * Return: size
 *
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0, n = 0, b = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		b = binary_tree_size(tree->left);
		n = binary_tree_size(tree->right);
		s = r + l + 1;
	}
	return (s);
}
