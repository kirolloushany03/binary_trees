#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree
 * @tree: root of the tree
 * @func: Pointer to the function to be called for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **nq =
		malloc(sizeof(binary_tree_t *) * binary_tree_size(tree)),
		*my_tmp;
	int i = 0, j = 0;

	if (!tree || !func || !nq)
	{
		free(nq);
		return;
	}
	nq[i++] = (binary_tree_t *)tree;
	while (i)
	{
		my_tmp = nq[j];
		func(my_tmp->n);
		if (my_tmp->left)
			nq[j + i++] = my_tmp->left;
		if (my_tmp->right)
			nq[j + i++] = my_tmp->right;
		i--, j++;
	}
	free(nq);
}

/**
 * binary_tree_size - measure the isze of a binary tree
 * @tree: root of the node tree
 *
 * Return: Size of the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
