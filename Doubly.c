#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertFirst(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
}

void insertLast(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(int val, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position not valid\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) { printf("List empty\n"); return; }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}

void deleteLast() {
    if (head == NULL) { printf("List empty\n"); return; }
    if (head->next == NULL) {
        free(head); head = NULL; return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPos(int pos) {
    if (head == NULL) { printf("List empty\n"); return; }
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL) { printf("Position not valid\n"); return; }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    free(temp);
}

void display() {
    struct Node* temp = head;
    if (head == NULL) { printf("List empty\n"); return; }
    printf("List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, val, pos;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert First\n2. Insert Last\n3. Insert at Position\n");
        printf("4. Delete First\n5. Delete Last\n6. Delete at Position\n");
        printf("7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); insertFirst(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insertLast(val); break;
            case 3: printf("Enter value & position: "); scanf("%d %d", &val, &pos); insertAtPos(val,pos); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: printf("Enter position: "); scanf("%d", &pos); deleteAtPos(pos); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
