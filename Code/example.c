#include<stdio.h>
#include<ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
   stack[++top] = item;
}

char pop() {
   if(top == -1)
      return -1;
   else
      return stack[top--];
}

int precedence(char x) {
   if(x == '(')
      return 0;
   if(x == '+' || x == '-')
      return 1;
   if(x == '*' || x == '/')
      return 2;
}

int main() {
   char exp[SIZE];
   char *e, x;
   printf("Enter the expression : ");
   scanf("%s",exp);
   printf("\n");
   e = exp;
   
   while(*e != '\0') {
      if(isalnum(*e))
         printf("%c ",*e);
      else if(*e == '(')
         push(*e);
      else if(*e == ')') {
         while((x = pop()) != '(')
            printf("%c ", x);
      }
      else {
         while(precedence(stack[top]) >= precedence(*e))
            printf("%c ",pop());
         push(*e);
      }
      e++;
   }
   
   while(top != -1) {
      printf("%c ",pop());
   } 
   return 0;
}
