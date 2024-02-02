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
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		total = left - right;
	}
	return (total);
}
