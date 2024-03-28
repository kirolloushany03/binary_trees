#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right-rotates a binary tree
 * @tree: root from which to to rotate
 * Return: a pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rot_piv, *node_temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	rot_piv = tree->left;
	node_temp = rot_piv->right;
	rot_piv->right = tree;
	tree->left = node_temp;
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
