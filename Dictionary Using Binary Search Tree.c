#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    char word[20];
    char meaning[50];
    struct Node *left, *right;
} Node;

// Create new node
Node* newNode(char word[], char meaning[]) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, word);
    strcpy(node->meaning, meaning);
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
Node* insert(Node* root, char word[], char meaning[]) {
    if (!root) return newNode(word, meaning);
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);
    return root;
}

// Search in BST
Node* search(Node* root, char word[]) {
    if (!root || strcmp(word, root->word) == 0) return root;
    if (strcmp(word, root->word) < 0) return search(root->left, word);
    return search(root->right, word);
}

int main() {
    Node* root = NULL;
    root = insert(root, "book", "collection of pages");
    insert(root, "apple", "a fruit");
    insert(root, "cat", "an animal");

    char key[20];
    printf("Enter word to search: ");
    scanf("%s", key);

    Node* res = search(root, key);
    if (res)
        printf("Meaning: %s\n", res->meaning);
    else
        printf("Word not found!\n");
}
