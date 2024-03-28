#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse treee in preorder traversal and
 * call func for each node
 * @tree: root of binary tree to traverse
 * @func: function to call for each node value
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
