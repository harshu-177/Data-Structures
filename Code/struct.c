#include<stdio.h>

struct info{
    char name[20];
    char DOB[20];
    char USN[20];
    int marks[3];
};

int main() {
    struct info stud1;
    printf("Enter the name of the student 1 : \n");
    scanf("%s", &stud1.name);

    printf("Enter the DOB of the student 1 : \n");
    scanf("%s", &stud1.DOB);

    printf("Enter the USN number of student 1 : \n");
    scanf("%s", &stud1.USN);

    for(int i = 0; i < 3; i++) {
        printf("Enter the marks of subject %d : \n", i+1);
        scanf("%d", &stud1.marks[i]);
    }
    printf("Total marks : \n");
    int total = 0;
    for(int i = 0; i < 3; i++){
        total = total + stud1.marks[i];
    }
    printf("%d/300\n", total);
    return 0;
}
