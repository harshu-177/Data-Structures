# include <stdio.h>
# define Qsize 5

int count = 0;

void enqueue(int q[], int *rear) {
    if(count == Qsize) {
        printf("Queue Overflow\n");
        // return 0;
    }
    else {
        int item;
        printf("Enter the value to be inserted: \t");
        scanf("%d", &item);
        *rear = ((*rear) + 1) % Qsize;
        q[*rear] = item;
        count++;
    }
}

int dequeue(int q[], int *front) {
    int del_item;
    if(count==0) {
        printf("Queue Underflow\n");
        return -1;
    }
    del_item = q[*front];
    *front = ((*front) + 1) % Qsize;
    count--;
    return del_item; 
}

void display(int q[], int *front, int *rear) {
    int i;
    if (*front > *rear)
        printf("Queue is empty\n");
    else {
        printf("The contents of Queue are: \n");
        int f = *front;
        for(i = 0; i < count; i++){
            printf("%d\t", q[f]);
            f = (f + 1) % Qsize;
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int q[Qsize], front = 0, rear = -1, options, value, del_item;
    printf("Select the options :\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-EXIT.\n");
    while(1) {
        printf("Option: \t");
        scanf("%d", &options);
        printf("\n");
        switch (options)
        {
        case 1:
            
            enqueue(q, &rear);
            break;

        case 2:
            del_item = dequeue(q, &front);
            if (del_item == -1) 
                break;
            else
                printf("Element %d is deleted.\n", del_item);
                break;

        case 3:
            display(q, &front, &rear);
            break;

        case 4:
            printf("Queue Exited:\n");
            return 0;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    return 0;
}