#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a binary_tree_node to the left of parent
 * @parent: parent of the new node
 * @value: value of the new node
 * Return: pointer to newly created node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	new_node->left = parent->left;
	if (new_node->left)
		new_node->left->parent = new_node;
	parent->left = new_node;

	return (new_node);
}
