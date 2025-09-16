#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertFirst(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertLast(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtPos(int val, int pos) {
    if (pos == 1) {
        insertFirst(val);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    struct Node* temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) { printf("List empty\n"); return; }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        struct Node* del = head;
        temp->next = head->next;
        head = head->next;
        free(del);
    }
}

void deleteLast() {
    if (head == NULL) { printf("List empty\n"); return; }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next->next != head) temp = temp->next;
        struct Node* del = temp->next;
        temp->next = head;
        free(del);
    }
}

void deleteAtPos(int pos) {
    if (head == NULL) { printf("List empty\n"); return; }
    if (pos == 1) { deleteFirst(); return; }
    struct Node* temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++)
        temp = temp->next;
    struct Node* del = temp->next;
    if (del == head) { printf("Invalid position\n"); return; }
    temp->next = del->next;
    free(del);
}

void display() {
    if (head == NULL) { printf("List empty\n"); return; }
    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int ch, val, pos;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
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
