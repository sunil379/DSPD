#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Inorder traversal (Left, Root, Right)
void inorder_traversal(Node *root) {
    if (root == NULL) return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Preorder traversal (Root, Left, Right)
void preorder_traversal(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Postorder traversal (Left, Right, Root)
void postorder_traversal(Node *root) {
    if (root == NULL) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Manually creating a binary tree
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    Node *root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->right = create_node(6);

    // Perform tree traversals
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Free the allocated memory (optional for this simple example)
    // Note: In a real application, you should free all nodes

    return 0;
}
