#include "binary_trees.h"

/**
 * binary_tree_height_b - binary  tree
 * @tree: tree
 * Return: height
 *
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t ft = 0;
	size_t ri = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			ft = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			ri = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((ft > ri) ? ft : ri);
	}
}

/**
 * binary_tree_balance - balance factor
 * @tree: tree
 * Return: balanced factor
 *
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int ri = 0, ft = 0, total = 0;

	if (tree)
	{
		ft = ((int)binary_tree_height_b(tree->left));
		ri = ((int)binary_tree_height_b(tree->right));
		total = ft - ri;
	}
	return (total);
}
