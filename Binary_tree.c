#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Create a new Node
struct node* create(int value) 
{
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) 
{
  root->left = create(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) 
{
  root->right = create(value);
  return root->right;
}

// Inorder traversal
void inorderTraversal(struct node* root) 
{
  if (root == NULL) 
  return;
  inorderTraversal(root->left);
  printf("%d -> ", root->data);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) 
{
  if (root == NULL) 
  return;
  printf("%d -> ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) 
{
  if (root == NULL) 
  return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d -> ", root->data);
}

int main() 
{
  struct node* root = create(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}


