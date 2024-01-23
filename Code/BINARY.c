#include <stdio.h>

int binarySearch(char array[], char x, int low, int high) {
    while (low<=high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(void) {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    char array[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf(" %c", &array[i]);
    }
    char x;
    printf("Enter a character to search: ");
    scanf(" %c", &x);
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);
    return 0;
}
