#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is a full binary tree
 * @tree: root of tree to check
 * Return: 1 if binary tree is full, 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL || ((tree->left == NULL) ^ (tree->right == NULL)))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
}
