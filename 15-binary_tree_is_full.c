#include "binary_trees.h"
/**
 * binary_tree_is_full - tree is full or not
 * @tree: tree
 * Return: 1 or 0
 *
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int ft = 0, ri = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left && tree->right)
		{
			ft = binary_tree_is_full(tree->left);
			ri = binary_tree_is_full(tree->right);
			if (ft == 0 || ri == 0)
			{
				return (0);
			}
			return (1);
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
}
