#include "binary_trees.h"

/**
 * fix_balance - rebalance an avl tree on insertion (or deletion)
 * @tree: reference to the root of the tree
 * @value: newly added node
 */
void fix_balance(avl_t **tree, int value)
{
	int bfactor = binary_tree_balance(*tree);

	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}
/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value to insert into the AVL tree
 * Return: Pointer to the newly inserted node, or NULL if the insertion fails
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	bst_t *created_node = binary_tree_node(NULL, value), *curr_node = *tree;

	if (curr_node)
	{
		while (curr_node)
		{
			if (value == curr_node->n)
				free(created_node), created_node = curr_node = NULL;
			else if (value < curr_node->n && curr_node->left)
				curr_node = curr_node->left;
			else if (value > curr_node->n && curr_node->right)
				curr_node = curr_node->right;
			else
			{
				if (value < curr_node->n)
					curr_node->left = created_node;
				else
					curr_node->right = created_node;
				created_node->parent = curr_node;
				break;
			}
		}
	}
	else
		*tree = created_node;
	while (curr_node)
		fix_balance(curr_node == *tree ? tree : &curr_node, value),
			curr_node = curr_node->parent;
	return (created_node);
}
