#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int coeff, exp;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term into polynomial in decreasing order of exponent
Node* insertTerm(Node* poly, int coeff, int exp) {
    if (coeff == 0) return poly; // skip 0 terms
    Node* newNode = createNode(coeff, exp);

    // If list is empty or exp is greater than head
    if (!poly || exp > poly->exp) {
        newNode->next = poly;
        return newNode;
    }

    Node* curr = poly, *prev = NULL;
    while (curr && curr->exp >= exp) {
        if (curr->exp == exp) {  // merge same exponent
            curr->coeff += coeff;
            free(newNode);
            return poly;
        }
        prev = curr;
        curr = curr->next;
    }
    newNode->next = curr;
    prev->next = newNode;
    return poly;
}

// Display polynomial
void displayPoly(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Add two polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1) { result = insertTerm(result, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2) { result = insertTerm(result, p2->coeff, p2->exp); p2 = p2->next; }
    return result;
}

// Multiply two polynomials
Node* multiplyPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    for (Node* a = p1; a; a = a->next) {
        for (Node* b = p2; b; b = b->next) {
            result = insertTerm(result, a->coeff * b->coeff, a->exp + b->exp);
        }
    }
    return result;
}

// Free memory
void freePoly(Node* poly) {
    while (poly) {
        Node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

// Function to read polynomial from user
Node* inputPoly() {
    Node* poly = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly = insertTerm(poly, coeff, exp);
    }
    return poly;
}

int main() {
    Node* poly1 = NULL, *poly2 = NULL;

    printf("Enter first polynomial:\n");
    poly1 = inputPoly();

    printf("\nEnter second polynomial:\n");
    poly2 = inputPoly();

    printf("\nPolynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    Node* sum = addPoly(poly1, poly2);
    printf("\nAddition Result: ");
    displayPoly(sum);

    Node* product = multiplyPoly(poly1, poly2);
    printf("Multiplication Result: ");
    displayPoly(product);

    // Free memory
    freePoly(poly1);
    freePoly(poly2);
    freePoly(sum);
    freePoly(product);

    return 0;
}
