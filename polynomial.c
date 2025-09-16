#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node *next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert in descending order of exponent, merge if same exponent
void insertNode(Node** head, int coeff, int exp) {
    if (coeff == 0) return; // skip zero terms

    Node* newNode = createNode(coeff, exp);

    if (*head == NULL || (*head)->exp < exp) { 
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    if (temp && temp->exp == exp) { // merge terms
        temp->coeff += coeff;
        free(newNode);
        if (temp->coeff == 0) { // remove zero terms
            if (prev) prev->next = temp->next;
            else *head = temp->next;
            free(temp);
        }
    } else { 
        newNode->next = temp;
        if (prev) prev->next = newNode;
        else *head = newNode;
    }
}

void display(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }

    while (head) {
        if (head->exp == 0)
            printf("%d", head->coeff);
        else if (head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->exp);

        head = head->next;
        if (head) printf(" + ");
    }
    printf("\n");
}

Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1) {
        insertNode(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        insertNode(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

Node* multiplyPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    for (Node* a = p1; a; a = a->next) {
        for (Node* b = p2; b; b = b->next) {
            insertNode(&result, a->coeff * b->coeff, a->exp + b->exp);
        }
    }
    return result;
}

Node* inputPoly() {
    Node* head = NULL;
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertNode(&head, coeff, exp); // order is now auto-handled
    }
    return head;
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *sum = NULL, *pro = NULL;

    printf("Enter first polynomial:\n");
    poly1 = inputPoly();

    printf("Enter second polynomial:\n");
    poly2 = inputPoly();

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPoly(poly1, poly2);
    pro = multiplyPoly(poly1, poly2);

    printf("\nSum = ");
    display(sum);

    printf("Product = ");
    display(pro);

    return 0;
}
