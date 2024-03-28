#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left-rotates a binary tree
 * @tree: node at root of tree to be rotated
 * Return: pointer to new root after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rot_piv, *node_temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	rot_piv = tree->right;
	node_temp = rot_piv->left;
	rot_piv->left = tree;
	tree->right = node_temp;
	if (node_temp != NULL)
		node_temp->parent = tree;
	node_temp = tree->parent;
	tree->parent = rot_piv;
	rot_piv->parent = node_temp;
	if (node_temp != NULL)
	{
		if (node_temp->left == tree)
			node_temp->left = rot_piv;
		else
			node_temp->right = rot_piv;
	}

	return (rot_piv);
}
