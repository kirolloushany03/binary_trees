#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a binary_tree_node to the right of parent
 * @parent: parent of the new node
 * @value: value of the new node
 * Return: pointer to newly created node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	new_node->right = parent->right;
	if (new_node->right)
		new_node->right->parent = new_node;
	parent->right = new_node;

	return (new_node);
}
