#include "binary_trees.h"
/**
 * binary_tree_height - a binary tree
 * @tree: tree
 * Return: height
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
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
			ft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			ri = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((ft > ri) ? ft : ri);
	}
}
/**
 * binary_tree_depth - node from root
 * @tree: depth
 * Return: 0
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - linked list from depth
 * @head: pointer to head
 * @tree: node
 * @level: depth
 * Return: Nothing
 *
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *j, *aux;

	j = malloc(sizeof(link_t));
	if (j == NULL)
	{
		return;
	}
	j->n = level;
	j->node = tree;
	if (*head == NULL)
	{
		j->next = NULL;
		*head = j;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		j->next = NULL;
		aux->next = j;
	}
}
/**
 * recursion - recursive
 * @head: pointer head
 * @tree: check node
 * Return: Nothing
 *
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - lever-order
 * @tree: root
 * @func: function
 * Return: Nothing
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
