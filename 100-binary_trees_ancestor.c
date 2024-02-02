#include "binary_trees.h"

/**
 * binary_trees_ancestor - ancestor
 * @first: First n
 * @second: Second n
 * Return: ancestor node
 *
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *b, *r;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	b = first->parent;
	r = second->parent;
	if (b == NULL || first == r || (!b->parent && r))
	{
		return (binary_trees_ancestor(first, r));
	}
	else if (r == NULL || b == second || (!r->parent && b))
	{
		return (binary_trees_ancestor(b, second));
	}
	return (binary_trees_ancestor(b, r));
}
