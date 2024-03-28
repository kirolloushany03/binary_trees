#include "binary_trees.h"

/**
 * binary_tree_balance_helper - gets the height of a binary tree, not in edges
 * but in nodes
 * @tree: tree to get the height of
 * Return: height of the binary tree
*/
size_t binary_tree_balance_helper(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_balance_helper(tree->left);
	right_height = binary_tree_balance_helper(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - gets the balance factor of a binary tree
 * @tree: tree to check the balance of
 * Return: binary factor of the binary tree
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_balance_helper(tree->left)
		- binary_tree_balance_helper(tree->right));
}
