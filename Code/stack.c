#include <stdio.h>
#define stack_size 5

void push(int array[], int *top, int value){
    if (*top == stack_size - 1)
        printf("Stack Overflow\n");
    else {
        *top = *top + 1;
        array[*top] = value;
        printf("Element value %d is pushed into the stack.\n", value);
    }
    printf("\n");
}

void pop(int array[], int *top) {
    if (*top == -1)
        printf("Stack Underflow\n");
    else {
        int pop = array[*top];
        *top = *top - 1;
        printf("Element %d is deleted.\n", pop);
    }
    printf("\n");
}

void display(int array[], int top) {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Elements in the stack: \n");
        for (int i = top; i > -1; i--)
            printf("%d\n", array[i]);
    }
    printf("\n");
}

int main() {
    int array[stack_size], top = -1, value, options;
    while(1) {
        printf("Select the options :\n1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT.\n");
        printf("Option: \t");
        scanf("%d", &options);
        printf("\n");
        switch (options)
        {
        case 1:
            printf("Enter the value to be pushed: \t");
            scanf("%d", &value);
            push(array, &top, value);
            break;

        case 2:
            pop(array, &top);
            break;

        case 3:
            display(array, top);
            break;

        case 4:
            printf("Stack Exited:\n");
            return 0;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    return 0;
}
