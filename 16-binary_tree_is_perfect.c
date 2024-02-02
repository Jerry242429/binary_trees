#include "binary_trees.h"
/**
 * tree_is_perfect - a tree is perfect or not
 * @tree: tree
 * Return: 0
 *
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int ft = 0, ri = 0;

	if (tree->left && tree->right)
	{
		ft = 1 + tree_is_perfect(tree->left);
		ri = 1 + tree_is_perfect(tree->right);
		if (ri == ft && ri != 0 && ft != 0)
			return (ri);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree 
 * Return: 1 or 0 
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lt = tree_is_perfect(tree);
		if (lt != 0)
		{
			return (1);
		}
		return (0);
	}
}
