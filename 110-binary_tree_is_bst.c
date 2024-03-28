#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - helper to check check if binary tree is a binary search tree
 * @tree: root of tree
 * @lo: lowest value so far
 * @hi: highest value so far
 * Return: if the tree is a valid BST 1, else 0
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - check if a binary tree is a valid binary search tree
 * @tree:  root node of tree to check
 * Return: 1 if tree is a valid BST, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
