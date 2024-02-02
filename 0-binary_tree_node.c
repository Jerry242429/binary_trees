#include "binary_trees.h"

/**
 * binary_tree_node - binary node is created
 * @parent: in parent node
 * @value: node value
 * Return: the new node
 *
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nnode;

	nnode = malloc(sizeof(binary_tree_t));
	if (nnode == NULL)
	{
		return (NULL);
	}
	nnode->n = value;
	nnode->parent = parent;
	nnode->left = NULL;
	nnode->right = NULL;
	return (nnode);
}
