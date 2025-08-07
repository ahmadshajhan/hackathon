#include <stdio.h>
#include <stdlib.h>

// Define a general node
struct Node {
    int data;
    struct Node *next;
    struct Node *prev; // Used only in doubly
};

// Heads for each type of list
struct Node *singlyHead = NULL;
struct Node *doublyHead = NULL;
struct Node *circularHead = NULL;

// ===================================================
// SINGLY LINKED LIST OPERATIONS
// ===================================================
void insertSinglyFirst(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = singlyHead;
    singlyHead = newNode;
}

void insertSinglyLast(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!singlyHead) {
        singlyHead = newNode;
        return;
    }
    struct Node *temp = singlyHead;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertSinglyAt(int pos, int val) {
    if (pos <= 1) {
        insertSinglyFirst(val);
        return;
    }
    struct Node *temp = singlyHead;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteSinglyFirst() {
    if (!singlyHead) return;
    struct Node *temp = singlyHead;
    singlyHead = singlyHead->next;
    free(temp);
}

void deleteSinglyLast() {
    if (!singlyHead) return;
    if (!singlyHead->next) {
        free(singlyHead);
        singlyHead = NULL;
        return;
    }
    struct Node *temp = singlyHead;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteSinglyAt(int pos) {
    if (pos <= 1) {
        deleteSinglyFirst();
        return;
    }
    struct Node *temp = singlyHead;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp || !temp->next) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void searchSingly(int val) {
    int pos = 1;
    struct Node *temp = singlyHead;
    while (temp) {
        if (temp->data == val) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found\n");
}

void displaySingly() {
    struct Node *temp = singlyHead;
    printf("Singly: ");
    while (temp) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void mergeSingly() {
    struct Node *head2 = NULL;
    printf("Enter number of elements to merge: ");
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (!head2) head2 = newNode;
        else {
            struct Node *temp = head2;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    if (!singlyHead) singlyHead = head2;
    else {
        struct Node *temp = singlyHead;
        while (temp->next) temp = temp->next;
        temp->next = head2;
    }
}

// ===================================================
// DOUBLY LINKED LIST
// ===================================================
void insertDoublyFirst(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = doublyHead;
    if (doublyHead) doublyHead->prev = newNode;
    doublyHead = newNode;
}

void insertDoublyLast(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!doublyHead) {
        newNode->prev = NULL;
        doublyHead = newNode;
        return;
    }
    struct Node *temp = doublyHead;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertDoublyAt(int pos, int val) {
    if (pos <= 1) {
        insertDoublyFirst(val);
        return;
    }
    struct Node *temp = doublyHead;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteDoublyFirst() {
    if (!doublyHead) return;
    struct Node *temp = doublyHead;
    doublyHead = doublyHead->next;
    if (doublyHead) doublyHead->prev = NULL;
    free(temp);
}

void deleteDoublyLast() {
    if (!doublyHead) return;
    struct Node *temp = doublyHead;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else doublyHead = NULL;
    free(temp);
}

void deleteDoublyAt(int pos) {
    if (pos <= 1) {
        deleteDoublyFirst();
        return;
    }
    struct Node *temp = doublyHead;
    for (int i = 1; temp && i < pos; i++) temp = temp->next;
    if (!temp) {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

void searchDoubly(int val) {
    int pos = 1;
    struct Node *temp = doublyHead;
    while (temp) {
        if (temp->data == val) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found\n");
}

void displayDoubly() {
    struct Node *temp = doublyHead;
    printf("Doubly: ");
    while (temp) {
        printf("%d ↔ ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ===================================================
// CIRCULAR SINGLY LINKED LIST
// ===================================================
void insertCircularFirst(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    if (!circularHead) {
        newNode->next = newNode;
        circularHead = newNode;
    } else {
        struct Node *temp = circularHead;
        while (temp->next != circularHead)
            temp = temp->next;
        newNode->next = circularHead;
        temp->next = newNode;
        circularHead = newNode;
    }
}

void insertCircularLast(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    if (!circularHead) {
        newNode->next = newNode;
        circularHead = newNode;
    } else {
        struct Node *temp = circularHead;
        while (temp->next != circularHead)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = circularHead;
    }
}

void insertCircularAt(int pos, int val) {
    if (pos <= 1) {
        insertCircularFirst(val);
        return;
    }

    struct Node *temp = circularHead;
    int count = 1;
    while (count < pos - 1 && temp->next != circularHead) {
        temp = temp->next;
        count++;
    }

    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteCircularFirst() {
    if (!circularHead) return;
    if (circularHead->next == circularHead) {
        free(circularHead);
        circularHead = NULL;
    } else {
        struct Node *temp = circularHead;
        struct Node *last = circularHead;
        while (last->next != circularHead)
            last = last->next;
        circularHead = circularHead->next;
        last->next = circularHead;
        free(temp);
    }
}

void deleteCircularLast() {
    if (!circularHead) return;
    if (circularHead->next == circularHead) {
        free(circularHead);
        circularHead = NULL;
    } else {
        struct Node *temp = circularHead;
        struct Node *prev = NULL;
        while (temp->next != circularHead) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = circularHead;
        free(temp);
    }
}

void deleteCircularAt(int pos) {
    if (!circularHead) return;
    if (pos <= 1) {
        deleteCircularFirst();
        return;
    }
    struct Node *temp = circularHead;
    struct Node *prev = NULL;
    int count = 1;
    while (count < pos && temp->next != circularHead) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count != pos || temp == circularHead) {
        printf("Position out of bounds\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void searchCircular(int val) {
    if (!circularHead) {
        printf("Not found\n");
        return;
    }
    struct Node *temp = circularHead;
    int pos = 1;
    do {
        if (temp->data == val) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != circularHead);
    printf("Not found\n");
}

void displayCircular() {
    if (!circularHead) {
        printf("Circular: Empty\n");
        return;
    }
    struct Node *temp = circularHead;
    printf("Circular: ");
    do {
        printf("%d → ", temp->data);
        temp = temp->next;
    } while (temp != circularHead);
    printf("(back to head)\n");
}

// ===================================================
// MAIN MENU
// ===================================================
int main() {
    int choice, op, val, pos, listType;

    while (1) {
        printf("\nSelect List Type:\n1. Singly\n2. Doubly\n3. Circular Singly\n4. Exit\nChoice: ");
        scanf("%d", &listType);
        if (listType == 4) break;

        while (1) {
            printf("\n1. Insert First\n2. Insert Last\n3. Insert At\n4. Delete First\n5. Delete Last\n6. Delete At\n7. Search\n8. Display\n9. Merge (only singly)\n10. Back\nChoice: ");
            scanf("%d", &op);

            if (op == 10) break;

            if (op >= 1 && op <= 3) {
                printf("Enter value: ");
                scanf("%d", &val);
                if (op == 3) {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                }
            }

            if ((op == 6 || op == 3) && op != 3) {
                printf("Enter position: ");
                scanf("%d", &pos);
            }

            switch (listType) {
                case 1:
                    if (op == 1) insertSinglyFirst(val);
                    else if (op == 2) insertSinglyLast(val);
                    else if (op == 3) insertSinglyAt(pos, val);
                    else if (op == 4) deleteSinglyFirst();
                    else if (op == 5) deleteSinglyLast();
                    else if (op == 6) deleteSinglyAt(pos);
                    else if (op == 7) {
                        printf("Enter value to search: ");
                        scanf("%d", &val);
                        searchSingly(val);
                    }
                    else if (op == 8) displaySingly();
                    else if (op == 9) mergeSingly();
                    break;
                case 2:
                    if (op == 1) insertDoublyFirst(val);
                    else if (op == 2) insertDoublyLast(val);
                    else if (op == 3) insertDoublyAt(pos, val);
                    else if (op == 4) deleteDoublyFirst();
                    else if (op == 5) deleteDoublyLast();
                    else if (op == 6) deleteDoublyAt(pos);
                    else if (op == 7) {
                        printf("Enter value to search: ");
                        scanf("%d", &val);
                        searchDoubly(val);
                    }
                    else if (op == 8) displayDoubly();
                    break;
                case 3:
                    if (op == 1) insertCircularFirst(val);
                    else if (op == 2) insertCircularLast(val);
                    else if (op == 3) insertCircularAt(pos, val);
                    else if (op == 4) deleteCircularFirst();
                    else if (op == 5) deleteCircularLast();
                    else if (op == 6) deleteCircularAt(pos);
                    else if (op == 7) {
                        printf("Enter value to search: ");
                        scanf("%d", &val);
                        searchCircular(val);
                    }
                    else if (op == 8) displayCircular();
                    else printf("Other operations not implemented for Circular Singly\n");
                    break;
            }
        }
    }

    return 0;
}
