#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} charStack;

typedef struct {
    double data[MAX];
    int top;
} doubleStack;

// Char stack
void initCharStack(charStack *s) { s->top = -1; }
int isCharFull(charStack *s){ return s->top == MAX -1; }
int isEmptyChar(charStack *s) { return s->top == -1; }

void pushChar(charStack *s, char c) { s->data[++s->top] = c; }
char popChar(charStack *s) { return s->data[s->top--]; }
char peakChar(charStack *s){ return s->data[s->top]; }

// Double stack
void initDoubleStack(doubleStack *s) { s->top = -1; }
int isDoubleFull(doubleStack *s){ return s->top == MAX -1; }
int isEmptyDouble(doubleStack *s) { return s->top == -1; }

void pushDouble(doubleStack *s, double val) { s->data[++s->top] = val; }
double popDouble(doubleStack *s) { return s->data[s->top--]; }
double peakDouble(doubleStack *s){ return s->data[s->top]; }

// Operator precedence
int precedence(char op) {
    switch(op) {
        case '^' : return 3;
        case '*' : case '/' : return 2;
        case '+' : case '-' : return 1;
        default : return 0;
    }
}
int isRightAssociative(char op) { return op == '^'; }
int isOperator(char ch) { return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'); }

// Infix → Postfix
void infixToPostfix(char infix[], char postfix[]){
    charStack stack; initCharStack(&stack);
    int i = 0, k = 0;

    while(infix[i] != '\0'){
        if(isspace(infix[i])){ i++; continue; }

        if(isdigit(infix[i])){
            while(isdigit(infix[i]) || infix[i] == '.'){
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
        } 
        else if (infix[i] == '(') {
            pushChar(&stack, infix[i++]);
        } 
        else if (infix[i] == ')'){
            while(!isEmptyChar(&stack) && peakChar(&stack) != '('){
                postfix[k++] = popChar(&stack);
                postfix[k++] = ' ';
            }
            if(!isEmptyChar(&stack) && peakChar(&stack) == '(') popChar(&stack);
            i++;
        } 
        else if (isOperator(infix[i])) {
            char op = infix[i];
            while (!isEmptyChar(&stack) && isOperator(peakChar(&stack)) && 
                  ((precedence(peakChar(&stack)) > precedence(op)) || 
                  ((precedence(peakChar(&stack)) == precedence(op)) && !isRightAssociative(op)))) {
                postfix[k++] = popChar(&stack); 
                postfix[k++] = ' ';
            }
            pushChar(&stack, op);
            i++;
        }
        else {
            printf("Invalid character %c\n", infix[i]);
            exit(1);
        }
    }

    while(!isEmptyChar(&stack)){
        postfix[k++] = popChar(&stack);
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
}

// Postfix evaluation
double evaluatePostfix(char postfix[]) {
    doubleStack stack; initDoubleStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        if(isspace(postfix[i])){ i++; continue; }

        if(isdigit(postfix[i]) || (postfix[i] == '-' && isdigit(postfix[i+1]))){
            char num[50]; int j = 0;
            if(postfix[i] == '-') num[j++] = postfix[i++];
            while(isdigit(postfix[i]) || postfix[i] == '.'){
                num[j++] = postfix[i++];
            }
            num[j] = '\0';
            pushDouble(&stack, atof(num));
        }
        else if (isOperator(postfix[i])){
            double val2 = popDouble(&stack);
            double val1 = popDouble(&stack);
            switch(postfix[i]) {
                case '+' : pushDouble(&stack, val1 + val2); break;
                case '-' : pushDouble(&stack, val1 - val2); break;
                case '*' : pushDouble(&stack, val1 * val2); break;
                case '/' : pushDouble(&stack, val1 / val2); break;
                case '^' : pushDouble(&stack, pow(val1, val2)); break;
            }
            i++;
        } else {
            printf("Invalid token %c\n", postfix[i]);
            exit(1);
        }
    }
    return popDouble(&stack);
}

// Main
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix Expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix : %s\n", postfix);

    double result = evaluatePostfix(postfix);
    printf("Result : %.2f\n", result);
    return 0;
}
