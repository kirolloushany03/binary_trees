#include "binary_trees.h"

/**
 * binary_tree_nodes - count the number of nodes in a binary treee
 * with at least one child
 * @tree: root of the binary treee
 * Return: number of nodes in the binary tree that have at least one child
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left || tree->right)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	return (0);
}
