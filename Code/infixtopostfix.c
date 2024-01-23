#include <string.h>
#include <stdio.h>
#define STACK_SIZE 50


char postfix[STACK_SIZE], infix[STACK_SIZE], stack[STACK_SIZE];

int i, j, top = 0;

int lesspriority(char op, char ch) {
    int k, pv1 = -1, pv2 = -1;
    char operators[] = {'+', '-', '*', '/', '%', '^', '('};
    int priority_value[] = {0, 0, 1, 1, 2, 3, 4};
    if(ch == '(')
        return 0;
    for(k = 0; k < 7; k++) {
        if (op == operators[k])
            pv1 = priority_value[k];
    }
    for(k = 0; k < 7; k++) {
        if (ch == operators[k])
            pv2 = priority_value[k];
    }
    if (pv1 < pv2)
        return 1;
    else
        return 0;
}

void push(char op) {
    if (top == 0) {
        stack[top] = op;
        top++;
    }
    else {
        if(op != '(') {
            while(lesspriority(op, stack[top-1]) == 1 && top >  0) {
                postfix[j] = stack[--top];
                j++;
            }
        }
        stack[top] = op;
        top++;
    }
}

void pop() {
    while(stack[--top] != '(') {
        postfix[j] = stack[top];
        j++;
    }
}

int main() {
    char ch;
    printf("\nEnter Infix Expression : ");
    gets(infix);
    while((ch=infix[i++]) != '\0') {
        switch(ch) {
            case ' ': break;
            case '(':
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
                push(ch);
                break; 
            case ')':
                pop();
                break;
            default:
                postfix[j] = ch;
                j++;
        }
    }
    while(top > 0) {
        postfix[j] = stack[--top];
        j++;
    }
    postfix[j] = '\0';
    printf("\nInfix Expression : %s", infix);
    printf("\nPostfix Expression: %s", postfix);
    return 0;
}
