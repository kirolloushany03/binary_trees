#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a binary_tree_node to the right of parent
 * @parent: parent of the new node
 * @value: value of the new node
 * Return: pointer to newly created node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node || !parent)
		return (NULL);

	new_node->parent = parent;
	new_node->right = parent->right;
	new_node->left = NULL;
	if (new_node->right)
		new_node->right->parent = new_node;
	new_node->n = value;

	parent->right = new_node;

	return (new_node);
}
