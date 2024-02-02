#include "binary_trees.h"
/*
 * new_node - a new_node
 * @node: Type pointer
 * Return: the node
 *
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *j;

	j =  malloc(sizeof(link_t));
	if (j == NULL)
	{
		return (NULL);
	}
	j->node = node;
	j->next = NULL;

	return (j);
}
/**
 * free_q - free the nodes
 * @head: Node
 *
 */
void free_q(link_t *head)
{
	link_t *tnode;

	while (head)
	{
		tnode = head->next;
		free(head);
		head = tnode;
	}
}
/**
 * _push - pushes a node
 * @node: node of the tree
 * @head: head node
 * @tail: tail node
 *
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *j;

	j = new_node(node);
	if (j == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = j;
	*tail = j;
}
/**
 * _pop - pops a node
 * @head: head node
 *
 */
void _pop(link_t **head)
{
	link_t *tnode;

	tnode = (*head)->next;
	free(*head);
	*head = tnode;
}
/**
 * binary_tree_is_complete - if a binary tree is complete
 * @tree: pointer of node
 * Return: 1 or 0
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
