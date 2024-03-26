#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if <node> is a leaf node
 * @node: node to check
 * Return: 1 if it's a leaf node, 0 if it's not
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (!node->left && !node->right);
}
