#include<stdio.h>
#define Qsize 2
void enqueue(int q[], int *front, int *rear){
    if((*rear) == Qsize){
        printf("Queue overflow\n");
    }
    else {
        int value;
        printf("Enter the value to be inserted: \t");
        scanf("%d", &value);
        if(*front == -1 && *rear == -1){
            *front = *rear = 0;
        }     
        q[(*rear)++]=value;
    }
    printf("\n");
}
int dequeue(int q[], int *front, int *rear){
    if(*rear==-1){
        printf("Queue underflow\n\n");
        return -1;
    }
    else {
        if(*front==*rear){
            *front=-1;
            *rear=-1;
        }
        printf("\n");
        return q[(*front)++];
    }
}
void display(int q[], int *front, int *rear){
    int i;
    if (*rear == 0) 
        printf("Queue is empty\n");
    else{
        printf("The contents of Queue are :\n");
        for(i=*front;i<*rear;i++){
            printf("%d \t", q[i]);
        }
        printf("\n\n");
    }
    
}
int main() {
    int q[Qsize], front = -1, rear = -1, options, value, del_item;
    while(1) {
        printf("Select the options :\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-EXIT.\n");
        printf("Option: \t");
        scanf("%d", &options);
        printf("\n");
        switch (options)
        {
        case 1:
            enqueue(q, &front, &rear);
            break;

        case 2:
            del_item = dequeue(q, &front, &rear);
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
