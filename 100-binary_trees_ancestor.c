#include "binary_trees.h"

/**
 * binary_trees_ancestor - find lowest common ancesstor between two nodes
 * @first: first node
 * @second: second node
 * Return: return commmon ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	first_parent = first->parent, second_parent = second->parent;

	if (first == second_parent || !first_parent ||
	(!first_parent->parent && second_parent))
	{
		return (binary_trees_ancestor(first, second_parent));
	}
	else if (first_parent == second || !second_parent ||
	(!second_parent->parent && first_parent))
	{
		return (binary_trees_ancestor(first_parent, second));
	}
	return (binary_trees_ancestor(first_parent, second_parent));
}
