#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a binary_tree_node is a root node
 * @node: node to check
 * Return: 1 if node is a root, 0 if node is not a root
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node != NULL && node->parent == NULL);
}
