#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse treee in postorder traversal and
 * call func for each node
 * @tree: root of binary tree to traverse
 * @func: function to call for each node value
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
