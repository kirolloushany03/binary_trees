#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_is_complete_rec(const binary_tree_t *tree,
								size_t index, size_t size);

/**
 * binary_tree_is_complete - check if the binary tree is complete
 * @tree: root of the binary tree
 * Return: if the binary tree is complete, 1, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	return (tree && binary_tree_is_complete_rec(tree, 0, binary_tree_size(tree)));
}

/**
 * binary_tree_is_complete_rec - helper function to help with checking tree is
 * complete if a binary tree is complete
 * @tree: root of the tree
 * @index: idnex of node to check
 * @size: size of the tree
 * Return: 1 if the binary tree is complete, else 0
 */
int binary_tree_is_complete_rec(const binary_tree_t *tree,
								size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (binary_tree_is_complete_rec(tree->left, index * 2 + 1, size) &&
			binary_tree_is_complete_rec(tree->right, index * 2 + 2, size));
}
/**
 * binary_tree_size - get the size of a binary tree
 * @tree: root of the tree
 * Return: Size of the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
