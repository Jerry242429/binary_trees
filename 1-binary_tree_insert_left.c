#include "binary_trees.h"
/**
 * binary_tree_insert_left - left of the parent
 * @parent: the specified parent node
 * @value: node value
 * Return: NULL if it fails
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nnode;

	if (parent == NULL)
	{
		return (NULL);
	}

	nnode = binary_tree_node(parent, value);
	if (nnode == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		nnode->left = parent->left;
		parent->left->parent = nnode;
	}
	parent->left = nnode;
	return (nnode);
}
