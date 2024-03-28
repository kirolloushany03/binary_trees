#include "binary_trees.h"

/**
 * binary_tree_height - get the height of a binary tree
 * @tree: root node of the binary tree
 * Return: height of the binary tree starting at <tree>
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
