#include "binary_trees.h"

/**
 * binary_tree_uncle - gets the uncle of the current node
 * @node: node to get the uncle of
 * Return: pointer to the uncle of the current node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
