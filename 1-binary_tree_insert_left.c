#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a binary_tree_node to the left of parent
 * @parent: parent of the new node
 * @value: value of the new node
 * Return: pointer to newly created node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node || !parent)
		return (NULL);

	new_node->parent = parent;
	new_node->left = parent->left;
	new_node->right = NULL;
	if (new_node->left)
		new_node->left->parent = new_node;
	new_node->n = value;

	parent->left = new_node;

	return (new_node);
}
