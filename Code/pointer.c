#include <stdio.h>

int sum(int *num1, int *num2) {
    return *num1 + *num2;
}

int main() {
    int num1, num2;

    printf("Enter two integers to add: \n");
    scanf("%d%d", &num1, &num2);

    printf("Sum of the numbers = %d\n", sum(&num1, &num2));

    return 0; 
}
