#include "binary_trees.h"
/**
<<<<<<< HEAD
 * binary_tree_delete - recursion it free the node
=======
 * binary_tree_delete - free an entire tree using recursion it free the node
 * when theft and right are NULL
>>>>>>> e15a0a0b078f65e4d58b87e35a45908c466753ab
 * @tree: tree to free
 * Return: Nothing
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
