#include "binary_trees.h"

/**
 * binary_tree_depth - gets the depth of the node <tree> in its tree
 * @tree: node to check
 * Return: depth of the current node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
