#include "binary_trees.h"

/**
 * binary_tree_sibling - gets the sibling of the current node
 * @node: node to get the sibling of
 * Return: sibling node
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}
