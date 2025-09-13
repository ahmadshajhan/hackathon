#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   // total size of array

int arr[SIZE];
int top1 = -1;         // top of first stack
int top2 = SIZE;       // top of second stack

// Push in stack 1
void push1(int item) {
    if (top1 < top2 - 1) {
        arr[++top1] = item;
        printf("Pushed %d in Stack 1\n", item);
    } else {
        printf("Stack Overflow in Stack 1!\n");
    }
}

// Push in stack 2
void push2(int item) {
    if (top1 < top2 - 1) {
        arr[--top2] = item;
        printf("Pushed %d in Stack 2\n", item);
    } else {
        printf("Stack Overflow in Stack 2!\n");
    }
}

// Pop from stack 1
void pop1() {
    if (top1 >= 0) {
        printf("Popped %d from Stack 1\n", arr[top1--]);
    } else {
        printf("Stack Underflow in Stack 1!\n");
    }
}

// Pop from stack 2
void pop2() {
    if (top2 < SIZE) {
        printf("Popped %d from Stack 2\n", arr[top2++]);
    } else {
        printf("Stack Underflow in Stack 2!\n");
    }
}

// Display Stack 1
void display1() {
    if (top1 == -1) {
        printf("Stack 1 is Empty\n");
        return;
    }
    printf("Stack 1 elements: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Display Stack 2
void display2() {
    if (top2 == SIZE) {
        printf("Stack 2 is Empty\n");
        return;
    }
    printf("Stack 2 elements: ");
    for (int i = SIZE - 1; i >= top2; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n===== Multiple Stacks Menu =====\n");
        printf("1. Push in Stack 1\n");
        printf("2. Pop from Stack 1\n");
        printf("3. Display Stack 1\n");
        printf("4. Push in Stack 2\n");
        printf("5. Pop from Stack 2\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push in Stack 1: ");
                scanf("%d", &item);
                push1(item);
                break;
            case 2:
                pop1();
                break;
            case 3:
                display1();
                break;
            case 4:
                printf("Enter element to push in Stack 2: ");
                scanf("%d", &item);
                push2(item);
                break;
            case 5:
                pop2();
                break;
            case 6:
                display2();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
