#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

// Create new node
Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Prefix (Preorder)
void prefix(Node* root) {
    if (root) {
        printf("%c ", root->data);
        prefix(root->left);
        prefix(root->right);
    }
}

// Postfix (Postorder)
void postfix(Node* root) {
    if (root) {
        postfix(root->left);
        postfix(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    // Expression: (a+b)*(c-d)
    Node* root = newNode('*');
    root->left = newNode('+');
    root->right = newNode('-');
    root->left->left = newNode('a');
    root->left->right = newNode('b');
    root->right->left = newNode('c');
    root->right->right = newNode('d');

    printf("Prefix: ");
    prefix(root);

    printf("\nPostfix: ");
    postfix(root);
}
