#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int key;
    struct node *left, *right;
};

// Create a node
struct node *newNode(int item) 
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(struct node *root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}

// Insert a node
struct node *insert(struct node *node, int key) 
{
    if (node == NULL) // Return newnode if tree is empty
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

// Search a node
struct node *search(struct node* root, int key)
{
	if (root == NULL || root->key == key)
	    return root;
	if (root->key < key)
	    return search(root->right, key);
	return search(root->left, key);
}



// Get inorder successor
struct node *minValueNode(struct node *node) 
{
    struct node *current = node;
    while (current && current->left != NULL)// Leftmost leaf
        current = current->left;
    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{
  
    if (root == NULL) // If the tree is empty
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
    {
        // If the node is with only one child or no child
        if (root->left == NULL) 
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() 
{
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    if(search(root , 12))
    {
      printf("\nelement found");
    }
    else
    {
      printf("\nelement not found");
    }

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal: ");
    inorder(root);
}

