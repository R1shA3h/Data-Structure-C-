#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct node *right;
};

void inorder_traversal(struct node *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ->", root->key);
    inorder_traversal(root->right);
}

void preorder_traversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->key);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(struct node *root)
{
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ->", root->key);
}

struct Node *create_node(value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->key = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Node *insert_left(struct Node *root, int value)
{
    root->left = create_node(value);
    return root->left;
}

struct Node *insert_right(struct Node *root, int value)
{
    root->right = create_node(value);
    return root->right;
}

int main()
{
    struct node *root = create_node(1);
    insert_left(root, 12);
    insert_right(root, 9);

    insert_left(root->left, 5);
    insert_right(root->left, 6);

    printf("Inorder traversal \n");
    inorder_traversal(root);

    printf("\nPreorder traversal \n");
    preorder_traversal(root);

    printf("\nPostorder traversal \n");
    postorder_traversal(root);
}

// INSERTION
void insert(int data)
{
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    // if tree is empty, create root node
    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;

        while (1)
        {
            parent = current;

            // go to left of the tree
            if (data < parent->data)
            {
                current = current->leftChild;

                // insert to the left
                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            }

            // go to right of the tree
            else
            {
                current = current->rightChild;

                // insert to the right
                if (current == NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

// SEARCH OPERATION

struct node *search(int data)
{
    struct node *current = root;
    printf("Visiting elements: ");

    while (current->data != data)
    {
        if (current != NULL)
            printf("%d ", current->data);

        // go to left tree

        if (current->data > data)
        {
            current = current->leftChild;
        }
        // else go to right tree
        else
        {
            current = current->rightChild;
        }

        // not found
        if (current == NULL)
        {
            return NULL;
        }
    }
    return current;
}
