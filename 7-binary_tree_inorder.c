#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse treee in inorder traversal and
 * call func for each node
 * @tree: root of binary tree to traverse
 * @func: function to call for each node value
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
