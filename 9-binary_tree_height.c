#include "binary_trees.h"

/**
 * binary_tree_height - height of a binary tree
 * @tree: tree
 * Return: height
 *
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t n = 0;
	size_t b = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			n = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			b = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((n > b) ? l : r);
	}
}
