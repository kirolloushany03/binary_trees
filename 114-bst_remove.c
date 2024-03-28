#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - get minimum value in the bst
 * @root: root of the bst
 * Return: mimimum value in the bst
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - dlete a node from a bst
 * @root: root of bst
 * @node: node to delete from bst
 * Return: ptr to new root node after deletion
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *node_parent = node->parent, *in_parent_place = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (node_parent != NULL && node_parent->left == node)
			node_parent->left = node->right;
		else if (node_parent != NULL)
			node_parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = node_parent;
		free(node);
		return (node_parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (node_parent != NULL && node_parent->left == node)
			node_parent->left = node->left;
		else if (node_parent != NULL)
			node_parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = node_parent;
		free(node);
		return (node_parent == NULL ? node->left : root);
	}

	/* Two children */
	in_parent_place = inorder_successor(node->right);
	node->n = in_parent_place->n;

	return (bst_delete(root, in_parent_place));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: root node of the BST to remove a node from.
 * @node: current node in the BST.
 * @value: The value to remove from the BST.
 * Return: root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 * Return: new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
