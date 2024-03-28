#include "binary_trees.h"

/**
 * binary_tree_is_perfect_helper - helps check if a binary tree is peftect
 * by keeping track of expected depth and the curr depth
 * @node: current node in checking for perfection
 * @leaf_depth: depth at which leaf nodes should be found
 * @curr_depth: depth of <node>
 * Return: 1 if no rules are broken, 0 if any rules are broken
*/
int binary_tree_is_perfect_helper(const binary_tree_t *node,
	size_t leaf_depth, size_t curr_depth)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (leaf_depth == curr_depth);

	if (curr_depth >= leaf_depth)
		return (0);


	return (
		binary_tree_is_perfect_helper(node->left, leaf_depth, curr_depth + 1)
		&& binary_tree_is_perfect_helper(node->right, leaf_depth,
			curr_depth + 1));
}

/**
 * binary_tree_is_perfect_height - get the height of a binary tree
 * @tree: root node of the binary tree
 * Return: height of the binary tree starting at <tree>
*/
size_t binary_tree_is_perfect_height(const binary_tree_t *tree)
{
	if (!tree || !tree->left)
		return (0);

	return (1 + binary_tree_is_perfect_height(tree->left));
}

/**
 * binary_tree_is_perfect - checkk if tree is a perfect binary tree
 * @tree: tree to check
 * Return: 1 if it's perfect and 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = binary_tree_is_perfect_height(tree);

	return (binary_tree_is_perfect_helper(tree, depth, 0));
}
