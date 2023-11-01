#include "binary_trees.h"

/**
 * binary_tree_delete_node - Deletes a node with a specific.
 * @root: Pointer to the root node of the tree.
 * @value: The value of the node to delete.
 * Return: 1 if deletion was successful, 0 otherwise.
 */
int binary_tree_delete_node(binary_tree_t **root, int value)
{
	binary_tree_t *node_to_delete;
	binary_tree_t *parent;

	if (root == NULL || *root == NULL)
		return (0);

	node_to_delete = find_node_by_value(*root, value);

	if (node_to_delete == NULL)
		return (0);

	parent = node_to_delete->parent;

	if (parent != NULL)
	{
		if (parent->left == node_to_delete)
		{
			parent->left = node_to_delete->left ? node_to_delete->left : node_to_delete->right;
		}
		else
		{
			parent->right = node_to_delete->left ? node_to_delete->left : node_to_delete->right;
		}
	}
	else
	{
		if (node_to_delete->left)
			*root = node_to_delete->left;
		else
			*root = node_to_delete->right;
	}

	if (node_to_delete->left)
		node_to_delete->left->parent = parent;
	if (node_to_delete->right)
		node_to_delete->right->parent = parent;

	free(node_to_delete);

	return (1);
}
